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
    int sum=0;
     void convertedBST(TreeNode* root) {
        if (!root) return;

        convertedBST(root->right);

        sum += root->val;
        root->val = sum;

        convertedBST(root->left);
    }
    TreeNode* convertBST(TreeNode* root) {
        if(!root){
            return NULL;
        }
        convertedBST(root);
        return root;
    }
};