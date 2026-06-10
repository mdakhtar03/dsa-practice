/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL){
            return NULL;
        }
        if(root->val == p->val){
            return root;
        }
        if(root->val == q->val){
            return root;
        }
        

        TreeNode* leftAns = lowestCommonAncestor(root->left,p,q);

        TreeNode* rightAns = lowestCommonAncestor(root->right,p,q);
        
        // case1
        if(leftAns && rightAns){
            return root;
        }
        if(leftAns){
            return leftAns;
        }
        
        return rightAns;
        
        
    }
};