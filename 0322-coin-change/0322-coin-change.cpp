class Solution {
public:
    int solveUsingRec(vector<int>& coins, int amount, int i){
        if(amount == 0){
            return 0;
        }
        if(amount<0 || i>= coins.size()){
            return INT_MAX;
        }
        int pick = INT_MAX;

        if(amount>=coins[i]){
           int ans = solveUsingRec(coins, amount - coins[i], i);
           if(ans != INT_MAX){
            pick= ans + 1;
           }
        }
        
        int notPick = solveUsingRec(coins, amount, i + 1); 
    
        return min(pick,notPick);
    }
    int solveUsingMem(vector<int>& coins, int amount, int i,vector<vector<int>>& dp){
        if(amount == 0){
            return 0;
        }
        if(amount<0 || i>= coins.size()){
            return INT_MAX;
        }
        if(dp[amount][i] != -1){
            return dp[amount][i];
        }
        int pick = INT_MAX;

        if(amount>=coins[i]){
           int ans = solveUsingMem(coins, amount - coins[i], i,dp);
           if(ans != INT_MAX){
            pick= ans + 1;
           }
        }
        
        int notPick = solveUsingMem(coins, amount, i + 1,dp); 
        dp[amount][i] = min(pick,notPick);
        return min(pick,notPick);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(amount+1,vector<int>(n+1,-1));
        int ans =  solveUsingMem(coins,amount, 0,dp);
        if(ans == INT_MAX){
            return -1;
        }
        return ans;
    }
};