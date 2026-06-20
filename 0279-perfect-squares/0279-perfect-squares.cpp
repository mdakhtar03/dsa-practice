class Solution {
public:
      bool isPerfectSquare(int num) {
        int i=1;
        while(true){
            num=num-i;
            i=i+2;
            if(num==0){
                break;
            }
            else if(num<0){
                return 0;
            }
        }
        return 1;
    }
    int solveUsingRec(int n){
        //Base Case
        if(n==0){
            return 0;
        }
        int ans = INT_MAX;

        for(int i = 1; i*i <= n; i++) {
            ans = min(ans, 1 + solveUsingRec(n - i*i));
        }

        return ans;
    }
    
    int solveUsingMem(int n, vector<int> &dp){
        //Base Case
        if(n==0){
            return 0;
        }
        if(dp[n] != -1){
            return dp[n];
        }

        int ans = INT_MAX;

        for(int i = 1; i*i <= n; i++) {
            ans = min(ans, 1 + solveUsingMem(n - i*i,dp));
        }
        dp[n]=ans;
        return dp[n];
    }
    int numSquares(int n) {
        vector<int> dp(n+1,-1);
        return solveUsingMem(n,dp);
    }
};