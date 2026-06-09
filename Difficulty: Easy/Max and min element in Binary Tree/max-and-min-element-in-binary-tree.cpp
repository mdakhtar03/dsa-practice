/*
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution {
  public:
    void Max(Node* root, int &maxNode){
        
        if(!root){
            return;
        }
        maxNode = max(maxNode, root->data);
        Max(root->left, maxNode);
        Max(root->right,maxNode);
    }
    void Min(Node* root, int &minNode){
        
        if(!root){
            return;
        }
        minNode = min(minNode, root->data);
        Min(root->left, minNode);
        Min(root->right,minNode);
    }
    int findMax(Node *root) {
        // code here
        int maxNode = INT_MIN;
        Max(root,maxNode);
        return maxNode;
    }

    int findMin(Node *root) {
        int minNode = INT_MAX;
        Min(root,minNode);
        return minNode;
    }
};