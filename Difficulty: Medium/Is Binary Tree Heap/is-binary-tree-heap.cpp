/*
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    bool checkIsComplete(Node* root){
        queue<Node*> q;
        bool isNULL= false;
        q.push(root);
        while(!q.empty()){
            Node* temp = q.front();
            q.pop();
            if(temp == NULL){
                isNULL = true;
            }
            else{
                if(isNULL == true){
                    return false;
                }
                q.push(temp->left);
                q.push(temp->right);
            }
        }
        return true;
    }
    bool checkMaxHeap(Node* root){
        if(!root){
            return true;
        }
        if(root->left == NULL && root->right == NULL){
            return true;
        }
        bool leftAns = checkMaxHeap(root->left);
        bool rightAns = checkMaxHeap(root->right);
        bool leftNode = true;
        bool rightNode = true;
        if( root->right && root->right->data > root->data){
            rightNode = false;
        }
        if(root->left && root->left->data > root->data){
            leftNode = false;
        }
        
        bool currentNode = rightNode && leftNode;
        
        if(currentNode && leftAns && rightAns){
            return true;
        }
        
            
        return false;
        
        
    }
    bool isHeap(Node* tree) {
        bool isComplete = checkIsComplete(tree);
        bool isMaxHeap = checkMaxHeap(tree);
        return isComplete && isMaxHeap;
    }
};