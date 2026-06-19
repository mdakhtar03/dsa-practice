class Solution {
public:
    int solveUsingRec(vector<int>& nums, int curr, int prev){
        //Base Case
        if(curr>=nums.size()){
            return 0;
        }

            int include = 0;
        if(prev == -1 || nums[prev] < nums[curr]){
            include = 1 + solveUsingRec(nums, curr+1, curr);
        }

        int exclude = solveUsingRec(nums, curr+1, prev);
        return max(include, exclude);
    }
    
    int solveUsingMem(vector<int>& nums, int curr, int prev, vector<vector<int>> &dp){
        //Base Case
        if(curr>=nums.size()){
            return 0;
        }

        if( dp[curr][prev+1] != -1){
            return  dp[curr][prev+1];
        }

            int include = 0;
        if(prev == -1 || nums[prev] < nums[curr]){
            include = 1 + solveUsingMem(nums, curr+1, curr, dp);
        }

        int exclude = solveUsingMem(nums, curr+1, prev,dp);
        int finalAns =  max(include, exclude);
          dp[curr][prev+1] = finalAns;
          return finalAns;
    }



    int lengthOfLIS(vector<int>& nums) {
        int prev = -1;
        int curr=0;
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1)) ;
        return solveUsingMem(nums, curr, prev,dp);
    }
};