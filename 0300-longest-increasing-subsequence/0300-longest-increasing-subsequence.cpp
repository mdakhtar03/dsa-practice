class Solution {
public:
    int solveUsingRec(vector<int>& nums, int prev, int curr){
        //Base Case
        if(curr >= nums.size()){
            return 0;
        }

        
        int include = 0;
        if(prev == -1 || nums[prev]<nums[curr]){
            
            include = 1 + solveUsingRec(nums, curr, curr+1);
        }

        int exclude = solveUsingRec(nums, prev, curr+1);

        return max(include,exclude);

    }
    int solveUsingMem(vector<int>& nums, int prev, int curr,vector<vector<int>> &dp){
        //Base Case
        if(curr >= nums.size()){
            return 0;
        }
        
        if(dp[prev+1][curr] != -1){
            return dp[prev+1][curr];
        }
        
        int include = 0;
        if(prev == -1 || nums[prev]<nums[curr]){
            
            include = 1 + solveUsingMem(nums, curr, curr+1,dp);
        }

        int exclude = solveUsingMem(nums, prev, curr+1,dp);

        dp[prev+1][curr] = max(include,exclude);
        return dp[prev+1][curr];
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));

        return solveUsingMem(nums,-1,0,dp);
    }
};