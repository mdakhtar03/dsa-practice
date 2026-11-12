class Solution {
public:
    int solveUsingRec(int n){
        //Base Case
        if(n==1 || n==0) return 1;

        int step = solveUsingRec(n-1) + solveUsingRec(n-2);
        return step;
    }

    int solveUsingMem(int n,vector<int> &dp){
        //Base Case
        if(n==1 || n==0) return 1;
        if(dp[n] != -1){
            return dp[n];
        }
        int step = solveUsingMem(n-1,dp) + solveUsingMem(n-2,dp);
        dp[n] = step;
        return step;
    }

    int solveUsingTabulation(int n){
        vector<int> dp(n+1,-1);
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2; i<=n; i++){
            dp[i] = dp[i-1]+dp[i-2];
        }
        return dp[n];
    }

    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        // return solveUsingMem(n,dp);
        return solveUsingTabulation(n);
    }
};