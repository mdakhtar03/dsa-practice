class Solution {
public:
    void solveUsingRec(vector<int>& nums,
                       vector<vector<int>>& ans,
                       vector<int>& store,
                       int index) {

        if(index == nums.size()) {
            ans.push_back(store);
            return;
        }

        // Include
        store.push_back(nums[index]);
        solveUsingRec(nums, ans, store, index + 1);

        // Backtrack
        store.pop_back();

        // Exclude
        solveUsingRec(nums, ans, store, index + 1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int index=0;
        vector<int> store;
         solveUsingRec(nums, ans, store,index);
        return ans;
    }
};