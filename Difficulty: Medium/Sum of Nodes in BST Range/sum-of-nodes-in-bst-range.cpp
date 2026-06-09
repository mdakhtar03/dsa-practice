/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
      void buildValues(Node* root, vector<int> &arr){
        if(root == NULL){
            return;
        }
        //LNR
        buildValues(root->left, arr);
        arr.push_back(root->data);
        buildValues(root->right,arr);
        
    }
    int nodeSum(Node* root, int l, int r) {
        vector<int> arr;
        int sum=0;
        buildValues(root, arr);
        
        for(auto &num:arr){
            if(num>=l && num<=r){
                sum += num;
            }
        }
        return sum;
    }
    
    
    
    
    
    
    
    
    
    
    
    
};
