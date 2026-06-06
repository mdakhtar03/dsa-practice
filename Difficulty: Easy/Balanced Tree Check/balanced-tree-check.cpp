/*
Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    int getHeight(Node* root){
        if(root == NULL){
            return 0;
        }
        
        int leftDepth = getHeight(root->left);
        int rightDepth = getHeight(root->right);
        return max(leftDepth,rightDepth)+1;
        
    }
    bool isBalanced(Node* root) {
        // code here
        if(root == NULL){
            return 1;
        }
        
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);
        
        int ans = abs(leftHeight - rightHeight );
        
        if(ans > 1){
            return 0;
        }
        
        else{
            bool leftAns = isBalanced(root->left);
            bool rightAns = isBalanced(root->right);
            if(leftAns == true && rightAns == true){
                return 1;
            }
            else{
                return 0;
            }
        }
        
        
    }
};