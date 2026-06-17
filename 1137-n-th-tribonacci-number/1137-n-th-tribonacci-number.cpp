class Solution {
public:
    int solveUsingRec(int n){
        if(n == 0){
            return 0;
        }
        if(n==1 || n== 2){
            return 1;
        }

        int ans = solveUsingRec(n-1)+solveUsingRec(n-2)+solveUsingRec(n-3);
        return ans;
    }
    int solveUsingMem(int n, vector<int> &dp){
        if(n == 0){
            return 0;
        }
        if(n==1 || n== 2){
            return 1;
        }
        if(dp[n] != -1){
            return dp[n];
        }

        dp[n]= solveUsingMem(n-1,dp)+solveUsingMem(n-2,dp)+solveUsingMem(n-3,dp);
        return dp[n];
    }
    int tribonacci(int n) {
         vector<int> dp(n+1,-1);
        return solveUsingMem(n,dp);
    }
};