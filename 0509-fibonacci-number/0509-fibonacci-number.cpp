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
    //Bottom up approach
    int solveUsingTabulation(int n){
        // Step 1: figure out the DP
        if(n==0) return 0;

        if(n==1) return 1;

        // vector<int> dp(n+1, -1);

        //Step 2: Analyse Base case and filled the DP
        // dp[0] = 0;
        // dp[1] = 1;

        //Step 3: Loop logic
        int curr = 0;  int prev1 = 0; int prev2 = 1;
        for(int i=2; i<=n ; i++){
            // int ans = dp[i-1] + dp[i-2];
           
            
            curr = prev1 + prev2;
            prev1 = prev2;
            prev2 = curr;
        }

        return curr;
    }

    int fib(int n) {
        // vector<int> dp(n+1,-1);
        return solveUsingTabulation(n);

        

    }
};