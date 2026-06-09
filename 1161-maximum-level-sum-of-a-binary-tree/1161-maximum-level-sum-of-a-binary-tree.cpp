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
    int maxLevelSum(TreeNode* root) {
        
        queue<TreeNode*> q;
        int Level = 0;
        int ans = 0;
        int sum=0;
        int maxSum = INT_MIN;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            TreeNode *temp = q.front();
            q.pop();
            if(temp == NULL){
                ++Level;
                if(sum>maxSum){
                    maxSum = sum;
                    ans = Level;
                    
                }
                sum=0;
                if(!q.empty()){
                    q.push(NULL);
                }
            }
            if(temp)
            sum = sum+temp->val;

            if(temp){
                if(temp->left)
                q.push(temp->left);
            }
            if(temp){
                if(temp->right)
                q.push(temp->right);
            }

        }
    return ans;

    }
};