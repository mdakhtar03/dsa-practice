/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void buildLevelOrder(queue<TreeNode*> &q,vector<vector<int>> &levelOrderAns,vector<int> &ans){
    
     while(!q.empty()){
        TreeNode* Ptr = q.front();
        q.pop();
        
        if(Ptr == NULL){
            levelOrderAns.push_back(ans);
            ans.clear();
            
            if(!q.empty())
            q.push(NULL);
        }

        else{
            ans.push_back(Ptr->val);
            if(Ptr->left){
                q.push(Ptr->left);
            }
            if(Ptr -> right){
                q.push(Ptr->right);
            }
        }

     }
    


    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr){
            return {};
        }
       queue<TreeNode*> q;
       q.push(root);
       q.push(NULL);
       vector<vector<int>> levelOrderAns;
       vector<int> ans;
       buildLevelOrder(q, levelOrderAns, ans);
        return levelOrderAns;
    }
};