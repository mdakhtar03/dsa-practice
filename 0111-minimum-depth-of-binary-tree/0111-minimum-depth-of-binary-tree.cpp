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

    void solve(TreeNode* root, int &minDepth,int count){
        if(!root){
          return;  
        } 

        if(root->left == NULL && root->right == NULL){
            minDepth = min(count, minDepth);
            return;
        }
            

        if(count>=minDepth) return;

        
        
        solve(root->left,minDepth, count+1);
        solve(root->right,minDepth, count+1);
    }

    int minDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int minDepth = INT_MAX;
        int count = 1;
        solve(root, minDepth, count);

        return minDepth;
    }
};