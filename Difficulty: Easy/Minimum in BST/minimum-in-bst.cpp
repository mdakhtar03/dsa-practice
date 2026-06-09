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
    int minValue(Node* root) {
        if(!root){
            return -1;
        }
        if(root->left == NULL){
            return root->data;
        }
        
        int ans = minValue(root->left);
    }
};