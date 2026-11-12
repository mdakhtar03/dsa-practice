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
        // vector<int> dp(n+1,-1);
        // dp[0] = 1;
        // dp[1] = 1;
        int prev1 = 1, prev2 = 1;
        int curr = 1;
        for(int i=2; i<=n; i++){
            curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return curr;
    }

    int climbStairs(int n) {
        // vector<int> dp(n+1, -1);
        // return solveUsingMem(n,dp);
        return solveUsingTabulation(n);
    }
};