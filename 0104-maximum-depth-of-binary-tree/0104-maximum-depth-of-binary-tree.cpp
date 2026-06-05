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

    void findAns(TreeNode* Ptr, int &ans, int &maxH){
        if(Ptr == NULL){
            ans = max(maxH,ans);
            return;
        }
        maxH = maxH+1;
        
            findAns(Ptr->left, ans, maxH);
            
            findAns(Ptr->right, ans, maxH);


            maxH = maxH-1;
        
    }

    int maxDepth(TreeNode* root) {
        int ans =0;
        if(root == NULL){
            return ans;
        }
        int maxH = 0;
        TreeNode* Ptr = root;
        findAns(Ptr, ans, maxH);
        return ans;
    }
};