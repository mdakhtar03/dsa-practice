/* A binary tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
  void builtAns(queue<Node*> nodes,vector<int> &ans)
  {
    
    while(!nodes.empty()){
        
    Node* Ptr = nodes.front();
    ans.push_back(Ptr->data);
    if(Ptr->left != NULL)
    nodes.push(Ptr->left);
    
    if(Ptr->right != NULL){
      nodes.push(Ptr->right);  
    }
    
    nodes.pop();
    }
    
    
  }
    vector<int> levelOrder(Node *root) {
        if(root == NULL){
            return {};
        }
        queue<Node*> nodes;
        nodes.push(root);
        vector<int> ans;
        builtAns(nodes, ans);
        return ans;
    }
};