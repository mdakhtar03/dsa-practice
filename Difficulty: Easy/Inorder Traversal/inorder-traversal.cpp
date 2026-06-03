/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    void inOrderAns(vector<int> &ans, Node *ptr){
        if(ptr == NULL){
            return;
        }
        inOrderAns(ans, ptr->left);
        ans.push_back(ptr->data);
        inOrderAns(ans,ptr->right);
    }
    
    vector<int> inOrder(Node* root) {
       vector<int> ans;
       Node *ptr = root;
       inOrderAns(ans,ptr);
       return ans;
    }
};
















