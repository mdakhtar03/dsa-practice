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
   void findAns(int &ans, int &MaxH, Node* Ptr){
     if(Ptr == NULL){
         ans = max(ans,MaxH);
         return;
     }
     MaxH++;
     
     findAns(ans, MaxH, Ptr->left);
     findAns(ans, MaxH, Ptr->right);
     MaxH--;
 }
    int height(Node* root) {
        // code here
        int MaxH =0;
        int ans =0;
        if(root == NULL){
            return ans;
        }
        Node* Ptr = root;
        findAns(ans, MaxH, Ptr);
        
        return ans-1;
    }
};