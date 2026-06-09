/*
Node is as follows
class Node {
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
    void buildValues(Node* root, vector<int> &arr){
        if(root == NULL){
            return;
        }
        //LNR
        buildValues(root->left, arr);
        arr.push_back(root->data);
        buildValues(root->right,arr);
        
    }
    bool findTarget(Node* root, int k) {
        vector<int> arr;
        buildValues(root, arr);

        int i=0;
        int j=arr.size()-1;

        while(i<j){
            if(arr[i]+arr[j] == k){
                return true;
            }
            else if(arr[i]+arr[j]>k){
                j--;
            }
            else{
                i++;
            }

        }
        return false;
    }
};