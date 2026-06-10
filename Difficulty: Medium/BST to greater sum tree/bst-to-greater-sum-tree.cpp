/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};*/

class Solution {
  public:
  int sum=0;
    void transformTree(Node *root) {
        if(root==NULL){
            return;
        }
        transformTree(root->right);
        int curr = root->data;
        root->data = sum;  
        sum += curr;
        transformTree(root->left);
     
    }
};