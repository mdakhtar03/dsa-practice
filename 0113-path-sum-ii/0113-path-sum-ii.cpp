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
    void solve(TreeNode* root, int &targetSum,int &sum,vector<vector<int>> &ans, vector<int> &path)
    {
        if(root == NULL){
            return;
        }
        sum += root->val;
        path.push_back(root->val);
        if(root->left == NULL && root->right == NULL){
            if(sum == targetSum){
                ans.push_back(path);
            }
            sum -= root->val;
            path.pop_back();
            return;
        }

        solve(root->left, targetSum, sum, ans, path);
        solve(root->right, targetSum, sum, ans,path);
        sum -= root->val;
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
      vector<vector<int>> ans;
        vector<int> path;
        int sum=0;
        solve(root, targetSum, sum, ans ,path);
        return ans;
    }
};