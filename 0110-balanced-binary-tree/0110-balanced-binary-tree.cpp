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
    int solve(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int leftAns = solve(root->left);
        if(leftAns == -1){
            return -1;
        }
        int rightAns = solve(root->right);
        if(rightAns == -1){
            return -1;
        }
        int ans = max(leftAns,rightAns)+1;
        if(abs(leftAns - rightAns) > 1){
                return -1;
            }

        return ans;

    
    }
    bool isBalanced(TreeNode* root) {
        return solve(root) != -1;
    }
};