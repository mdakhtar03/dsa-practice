class Solution {
public:
    int solveUsingRec(vector<int>& coins, int amount){
        if(amount == 0){
            return 0;
        }

        int mini = INT_MAX;

        for(int i=0;i<coins.size();i++){
            if(coins[i]<=amount){

                int recursionAns = solveUsingRec(coins, amount-coins[i]);
                if(recursionAns != INT_MAX){
                    mini = min(mini , recursionAns+1);
                }
            }
        }

        return mini;
    }
    int solveUsingMem(vector<int>& coins, int amount, vector<int> &dp){
        if(amount == 0){
            return 0;
        }

        int mini = INT_MAX;
        if(dp[amount] != -1){
            return dp[amount];
        }

        for(int i=0;i<coins.size();i++){
            if(coins[i]<=amount){

                int recursionAns = solveUsingMem(coins, amount-coins[i],dp);
                if(recursionAns != INT_MAX){
                    mini = min(mini , recursionAns+1);
                }
            }
        }
        dp[amount] = mini;
        return dp[amount];
    }
    
    int coinChange(vector<int>& coins, int amount) {
        
        vector<int> dp(amount+1,-1);
        int ans = solveUsingMem(coins,amount,dp);
        if(ans != INT_MAX)
        return ans;

        return -1;
    }
};