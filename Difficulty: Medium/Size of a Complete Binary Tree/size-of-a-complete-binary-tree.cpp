class Solution {
  public:
    int countNodes(Node* root, int &ans){
        if(root == NULL){
            return 0;
        }

        ans++;
        countNodes(root->left, ans);
        countNodes(root->right, ans);
        return ans;

    }
    int countNodes(Node* root) {
        int ans=0;
        if(!root){
            return ans;
        }
        return countNodes(root, ans);
    }
};