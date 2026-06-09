/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void buildValues(TreeNode* root, vector<int> &arr){
        if(root == NULL){
            return;
        }
        //LNR
        buildValues(root->left, arr);
        arr.push_back(root->val);
        buildValues(root->right,arr);
        
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> arr;
        buildValues(root, arr);

        int i=0;
        int j=arr.size()-1;

        while(i<j){
            if(arr[i]+arr[j] == k){
                return true;
            }
            else if(arr[i]+arr[j]>k){
                j--;
            }
            else{
                i++;
            }

        }
        return false;
    }
};