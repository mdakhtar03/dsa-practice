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
    int rangeSumBST(TreeNode* root, int low, int high) {
        vector<int> arr;
        unsigned int sum = 0;
        buildValues(root, arr);
        for(auto &num:arr){
            if(num>=low && num<=high){
                sum += num;
            }
        }
        return sum;
    }
};