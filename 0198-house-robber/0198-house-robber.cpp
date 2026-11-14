class Solution {
public:
    int solveUsingRec(int i, vector<int> &nums){
        if(i>=nums.size()){
            return 0;
        }

        int firstWay = nums[i] + solveUsingRec(i+2, nums);

        int secondWay = solveUsingRec(i+1, nums);

        return max(firstWay, secondWay);

    }
    int solveUsingMem(int i, vector<int> &nums, vector<int> &dp){
        if(i>=nums.size()){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }

        int firstWay = nums[i] + solveUsingMem(i+2, nums,dp);

        int secondWay = solveUsingMem(i+1, nums,dp);

        dp[i]= max(firstWay, secondWay);
        return dp[i];

    }
    int rob(vector<int>& nums) {
        vector<int> dp(int(nums.size()+1),-1);
        return solveUsingMem(0, nums,dp);
    }
};