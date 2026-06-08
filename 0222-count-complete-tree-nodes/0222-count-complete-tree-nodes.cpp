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
    int findleftHeight(TreeNode *root){
        int h=0;
        while(root){
            h++;
            root = root->left;
        }
        return h;
    }
    int findrightHeight(TreeNode* root){
        int h=0;
        while(root){
            h++;
            root = root->right;
        }
        return h;
    }

    int countNodes(TreeNode* root) {
        
        if(!root){
            return 0;
        }
        int leftHeight = findleftHeight(root);
        int rightHeight = findrightHeight(root);

        if(leftHeight == rightHeight){
            return (1<<leftHeight)-1;
        }

        int leftCount = countNodes(root->left);
        int rightCount = countNodes(root->right);

        return leftCount+rightCount+1;

    }
};