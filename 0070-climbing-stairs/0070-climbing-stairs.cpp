class Solution {
public:
    int solveUingRec(int n){
         if(n==1){
            return 1;
        }
        if(n==0){
            return 1;
        }

        int recAns = solveUingRec(n-1) + solveUingRec(n-2);
        return recAns;
    }

    int solveUingMem(int n, vector<int> &dp){
         if(n==1 || n==0){
            return 1;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        

        int ans = solveUingMem(n-1,dp) + solveUingMem(n-2,dp);
        dp[n] = ans;
        return dp[n];
    }
    


    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
       return solveUingMem(n,dp);
    }
};