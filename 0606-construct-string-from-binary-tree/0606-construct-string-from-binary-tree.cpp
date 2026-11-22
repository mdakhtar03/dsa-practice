class Solution {
public:
    string solve(TreeNode* root) {

        // Base case
        if(root == nullptr) {
            return "";
        }

        // Current node
        string ans = to_string(root->val);

        if(!root->left && root->right){
            ans += "()";
        }
        // Case 1: Left child exists
        if(root->left) {
            ans += "(";
            ans += solve(root->left);
            ans += ")";
        }

        // Case 2: Right child exists
        if(root->right) {

            // What if left child doesn't exist?

            ans += "(";
            ans += solve(root->right);
            ans += ")";
        }

        return ans;
    }

    string tree2str(TreeNode* root) {
        return solve(root);
    }
};