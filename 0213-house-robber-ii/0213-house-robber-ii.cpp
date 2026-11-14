class Solution {
public:
    int solveUsingRec(int i, int j, vector<int>& nums){
        if(i>j){
            return 0;
        }

        int firstWay = nums[i] + solveUsingRec(i+2,j,nums);

        int secondWay = solveUsingRec(i+1,j, nums);

        return max(firstWay, secondWay);

    }
    int solveUsingMem(int i, int j, vector<int>& nums,vector<int>& dp){
        if(i>j){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        int firstWay = nums[i] + solveUsingMem(i+2,j,nums,dp);

        int secondWay = solveUsingMem(i+1,j, nums,dp);

        dp[i] = max(firstWay, secondWay);
        return dp[i];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int> dp(n+1, -1);
        vector<int> dp2(n+1, -1);
        return max(solveUsingMem(0,n-2,nums,dp),solveUsingMem(1,n-1,nums,dp2));
    }
};