class Solution {
public:
    int solve(int i, vector<int>& costs, int n){

        if(i == n ){
            return 0;
        }

        int option1 = INT_MAX;

        int option2 = INT_MAX;
        
        int option3 = INT_MAX;

        if( i+1 <= n){
            option1 = costs[i] + abs(i+1-i)*abs(i+1-i) + solve(i+1,costs,n);
        }
         if(i+2 <= n){
            option2 = costs[i+1] + abs(i+2-i)*abs(i+2-i) + solve(i+2, costs, n);
        }
        if(i + 3 <= n){
            option3 = costs[i+2] + abs(i+3-i)*abs(i+3-i) + solve(i+3, costs, n);
        }
        return min({option1, option2, option3});
    }

    int solveUsingMem(int i, vector<int>& costs, int n, vector<int> &dp){

        if(i == n ){
            return 0;
        }

        if(dp[i] != -1){
            return dp[i];
        }
        int option1 = INT_MAX;

        int option2 = INT_MAX;
        
        int option3 = INT_MAX;

        if( i+1 <= n){
            option1 = costs[i] + 1*1 + solveUsingMem(i+1,costs,n,dp);
        }
         if(i+2 <= n){
            option2 = costs[i+1] + 2*2 + solveUsingMem(i+2, costs, n,dp);
        }
        if(i + 3 <= n){
            option3 = costs[i+2] + 3*3 + solveUsingMem(i+3, costs, n,dp);
        }
        dp[i] = min({option1, option2, option3});
        return dp[i];
    }
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n+1 ,0);
        // int ans =  solveUsingMem(0,costs,n,dp);

        //Bottom Up 
        for(int i = n-1; i>=0 ; i--){
            int cost = INT_MAX;
            int j = i+1;
            if(j<=n){
                cost = dp[j] + costs[j-1] + (j-i)*(j-i);
            }
            j = i+2;
            if(j<=n){
                cost = min(cost, dp[j] + costs[j-1]+(j-i)*(j-i));
            }
            j=i+3;
            if(j<=n){
                cost = min(cost,dp[j]+costs[j-1]+(j-i)*(j-i));
            }
            dp[i] = cost;
        }


        return dp[0];
    }
};