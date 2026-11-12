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

    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return solveUsingMem(n,dp);
    }
};