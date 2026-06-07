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
    int getIndex(vector<int>& inorder, int element){
            for(int i=0; i<inorder.size(); i++){
                if(inorder[i]==element){
                    return i;
                }
            }
            return -1;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, int &postorderIndex, int startIndex, 
    int endIndex){
        if(postorderIndex<0){
            return NULL;
        }
        if(startIndex>endIndex){
            return NULL;
        }

        int  element = postorder[postorderIndex--];
        TreeNode* root = new TreeNode(element);
        int inorderElementIndex = getIndex(inorder,element);

        root->right = buildTree(inorder, postorder, postorderIndex,inorderElementIndex+1,endIndex);
        root->left = buildTree(inorder, postorder, postorderIndex, startIndex,inorderElementIndex-1);
        
        return root;
    }



    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        int postorderIndex = postorder.size()-1;
        int startIndex = 0;
        int endIndex = inorder.size()-1;

        return buildTree(inorder,postorder, postorderIndex, startIndex, endIndex);


    }
};