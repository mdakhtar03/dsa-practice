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
    int solveUsingTabulation(vector<int> &cost){
        vector<int> dp(int(cost.size())+2, -1);
        int n = cost.size();
        dp[n+1] = 0;
        dp[n] = 0;

        for(int i=n-1; i>=0;i--){
            dp[i] = cost[i] + min(dp[i+1],dp[i+2]);
        }
        return min(dp[0],dp[1]);
    }
    int minCostClimbingStairs(vector<int>& cost) {
    //     vector<int> dp(int(cost.size()), -1);
    //    int ans1= solveUsingRecMem(0,cost,dp);
    //    int ans2 = solveUsingRecMem(1,cost,dp);
    //    return min(ans1,ans2);

        return solveUsingTabulation(cost);
    }
};