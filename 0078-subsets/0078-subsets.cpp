class Solution {
public:
    vector<int> solveUsingRec(vector<int>& nums, vector<vector<int>> &ans,vector<int> &store,int index){
        //Base case
        vector<int> include;vector<int> exclude;
        if(index == nums.size()){
            //store ans
            ans.push_back(store);
            return store;
        }
        store.push_back(nums[index]);
        include = solveUsingRec(nums, ans,store, index+1);
        store.pop_back();
        exclude = solveUsingRec(nums, ans,store, index+1);
        return store;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int index=0;
        vector<int> store;
         solveUsingRec(nums, ans, store,index);
        return ans;
    }
};