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
    TreeNode* getMax(TreeNode* root){
        while(root->right){
            root=root->right;
        }
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL){
            return NULL;
        }

        //Case 1 if Both left and right are NULL
        if(root->val == key){
            if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
            }
            //Case 2 if left is NULL Only
            else if(root->left == NULL && root->right != NULL){
                TreeNode* temp = root;
                TreeNode *child = root->right;
                delete temp;
                return child;
            }
            else if(root->left != NULL && root->right == NULL ){
                TreeNode* temp = root;
                TreeNode *child = root->left;
                delete temp;
                return child;
            }

            else{
                TreeNode* maxNode = getMax(root->left);
                root->val = maxNode->val;
                root->left = deleteNode(root->left, maxNode->val);
                return root;
            }

        
        }

        if(key<root->val)
            root->left = deleteNode(root->left,key);
        else
            root->right = deleteNode(root->right,key);
        
        return root;
    }
};