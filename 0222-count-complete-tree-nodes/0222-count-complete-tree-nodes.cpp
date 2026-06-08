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
    int countNodes(TreeNode* root, int &ans){
        if(root == NULL){
            return 0;
        }

        ans++;
        countNodes(root->left, ans);
        countNodes(root->right, ans);
        return ans;

    }
    int countNodes(TreeNode* root) {
        int ans=0;
        if(!root){
            return ans;
        }
        return countNodes(root, ans);
    }
};