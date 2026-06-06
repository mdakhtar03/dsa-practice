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
int getIndex(int element,vector<int>& inorder){
    for(int i=0; i<inorder.size();i++){
        if(element == inorder[i]){
            return i;
        }
    }
    return -1;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder
,int &preorderIndex , int inorderStart, int inorderEnd){

    if(preorderIndex >= preorder.size()){
        return NULL;
    }

    if(inorderStart>inorderEnd){
        return NULL;
    }
    
    int element = preorder[preorderIndex++];
    TreeNode* root = new TreeNode(element);
    int elementIndexinInoder = getIndex(element, inorder);

    root->left = buildTree(preorder,inorder,preorderIndex,inorderStart, elementIndexinInoder-1);

    root->right = buildTree(preorder,inorder,preorderIndex, elementIndexinInoder+1, inorderEnd);
    return root;

}

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preoderIndex = 0;
        int inoderIndex =0;
        int inorderEnd = inorder.size()-1;
       return buildTree(preorder, inorder, preoderIndex,inoderIndex,
        inorderEnd);

    }
};