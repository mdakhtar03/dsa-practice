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
    
    void leftNode(Node *root, vector<int>& ans){
        
        if(root == NULL){
            return;
        }
        
        if(root->left == NULL && root -> right == NULL){
            return;
        }
        
        ans.push_back(root->data);
        
        if(root->left != NULL){
            leftNode(root->left, ans);
        }
        else {
            leftNode(root->right, ans);
        }
        
        
    }
  
  void leftLeafNode(Node *root, vector<int>& ans){
      
      if(root == NULL){
            return;
        }
      if(root->left == NULL && root->right == NULL){
          ans.push_back(root->data);
          return;
      }
      
      leftLeafNode(root->left, ans);
      leftLeafNode(root->right,ans);
   
  }
  
  void rightLeafNode(Node *root, vector<int>& ans){
      if(root == NULL){
            return;
        }
      if(root -> left == NULL && root->right == NULL){
          ans.push_back(root->data);
          return;
      }
      rightLeafNode(root->left,ans);
      rightLeafNode(root->right,ans);
  }
  void rightNode(Node *root, vector<int>& ans){
      
      if(root == NULL){
          return;
      }
      
      if(root->left == NULL && root -> right == NULL){
            return;
        }
        
        
        if(root->right != NULL){
            rightNode(root->right, ans);
             
        }
        else {
            rightNode(root->left, ans);
        }
        
        ans.push_back(root->data);   
   
      
  }
  
    vector<int> boundaryTraversal(Node *root) {
        vector<int> ans;
       if(root == NULL){
           return ans;
       }
       
       ans.push_back(root->data);
   
           
       leftNode(root->left,ans);
       leftLeafNode(root->left, ans);
       
       
       rightLeafNode(root->right, ans);
       rightNode(root->right,ans);
       
        return ans;
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
};