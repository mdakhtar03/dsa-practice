class Solution {
public:

    long long mod = 1000000007;
    int solveUsingRec(int n, int k, int target){
        //Base Case
        if(n<0 || target<0){
            return 0;
        }
        if(n == 0 && target != 0){
            return 0;
        }
        if(n == 0 && target == 0){
            return 1;
        }
        if(n != 0 && target == 0){
            return 0;
        }
        int ans = 0;
        for(int i=1;i<=k;i++){
            ans = ans+solveUsingRec(n-1,k,target-i);
        }
        return ans;
    }



    
    int solveUsingMem(int n, int k, int target, vector<vector<long long>> &dp){
        //Base Case
        if(n<0 || target<0){
            return 0;
        }
        if(n == 0 && target != 0){
            return 0;
        }
        if(n == 0 && target == 0){
            return 1;
        }
        if(n != 0 && target == 0){
            return 0;
        }
        if(dp[n][target] != -1){
            return dp[n][target];
        }


        long long ans = 0;
        for(int i=1;i<=k;i++){
            ans = (ans%mod+solveUsingMem(n-1,k,target-i,dp)%mod)%mod;
        }
        dp[n][target] = ans;
        return dp[n][target];
    }




    int numRollsToTarget(int n, int k, int target) {
        vector<vector<long long>> dp(n+1,vector<long long> (target+1, -1));
        return solveUsingMem(n,k,target, dp);
    }
};