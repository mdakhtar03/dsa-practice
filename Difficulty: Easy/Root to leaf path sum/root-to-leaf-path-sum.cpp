/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

/*you are required to
complete this function */
class Solution {
  public:
  
    void sumFun(Node *root, int &target, int &sum, bool &ans){
        
        if(root == NULL){
            return;
        }
        sum = sum + root->data;
         if(root-> left == NULL && root->right == NULL){
           
           if(sum == target){
               ans=true;
           }
           sum = sum - root->data;
           return;
       } 
       
       
       sumFun(root->left, target, sum, ans);
       
       sumFun(root->right,target, sum,ans);
       sum = sum - root->data;
       
    }
    bool hasPathSum(Node *root, int target) {
      bool ans = false;
      int sum=0;
      sumFun(root, target, sum, ans);
      return ans;
    }
};