/*
class Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void vectorAns(vector<int> &ans, Node* ptr){
       if( ptr == NULL ){
           return;
       } 
       
       ans.push_back(ptr->data);
      vectorAns(ans, ptr->left);
      vectorAns(ans, ptr->right);
       
    }
    vector<int> preOrder(Node* root) {
        // code here
        vector<int> ans;
        Node *ptr = root;
        vectorAns(ans, ptr);
        return ans;
    }
    
    
    
};