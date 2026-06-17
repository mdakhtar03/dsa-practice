class Solution {
public:
    int solveUsingRec(int n){
        if(n==0 || n==1){
            return n;
        }

        int recAns = solveUsingRec(n-1) + solveUsingRec(n-2);
        return recAns;
    }
    int solveUsingMem(int n, vector<int> &dp){
        if(n==0 || n==1){
            return n;
        }
        if(dp[n] != -1){
            return dp[n];
        }

        int ans = solveUsingMem(n-1,dp) + solveUsingMem(n-2,dp);
        dp[n] = ans;
        return dp[n];
    }


    int fib(int n) {
        vector<int> dp(n+1,-1);
        return solveUsingMem(n,dp);
    }
};