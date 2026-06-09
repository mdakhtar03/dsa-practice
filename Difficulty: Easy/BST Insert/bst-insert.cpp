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
    Node* insert(Node* root, int key) {
       if(!root){
           Node* newNode = new Node(key);
           return newNode;
       }
       
       if(key>root->data){
           
            root->right =  insert(root->right, key);
       }
        else{
            
       root->left =  insert(root->left, key);
        }
       
       return root;
       
    }
};