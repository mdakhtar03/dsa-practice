/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
  vector<int> leftView(Node *root, vector<int> &ans,int level){
      if(root == NULL){
          return ans;
      }
      
      if(level == ans.size()){
          ans.push_back(root->data);
      }
      leftView(root->left, ans, level+1);
      leftView(root->right, ans, level+1);
      
      return ans;
  }
    vector<int> leftView(Node *root) {
        vector<int> ans;
        int level=0;
        leftView(root, ans, level);
        return ans;
    }
};