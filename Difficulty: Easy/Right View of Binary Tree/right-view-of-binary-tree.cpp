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
  vector<int> rightView(Node *root, vector<int> &ans,int level){
      if(root == NULL){
          return ans;
      }
      
      if(level == ans.size()){
          ans.push_back(root->data);
      }
      rightView(root->right, ans, level+1);
      rightView(root->left, ans, level+1);
      
      return ans;
  }
    vector<int> rightView(Node *root) {
        //  code here
         vector<int> ans;
        int level=0;
        rightView(root, ans, level);
        return ans;
    }
};