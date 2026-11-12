class Solution {
public:
    int solveUsingRec(int i, vector<int> &cost){
        if(i>=cost.size()){
            return 0;
        }

        int ans = cost[i] + min(solveUsingRec(i+1, cost) , solveUsingRec(i+2,cost));

        return ans;
    }
    int solveUsingRecMem(int i, vector<int> &cost,vector<int> &dp){
        if(i>=cost.size()){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        int ans = cost[i] + min(solveUsingRecMem(i+1, cost,dp) , solveUsingRecMem(i+2,cost,dp));
        dp[i] = ans;
        return ans;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(int(cost.size()), -1);
       int ans1= solveUsingRecMem(0,cost,dp);
       int ans2 = solveUsingRecMem(1,cost,dp);
       return min(ans1,ans2);
    }
};