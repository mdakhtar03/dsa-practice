class Solution {
public:
    int solve(vector<int>& s, int i){
        if(i >= s.size()){
            return 0;
        }

        int result = INT_MIN;

        result = max(result, s[i] -solve(s, i+1));
        if(i+1<s.size())
        result = max(result, (s[i] + s[i+1] - solve(s,i+2)));
        if(i+2<s.size())
        result = max(result, (s[i] + s[i+1] + s[i+2] - solve(s,i+3)));
        return result;
    }
    int solveMem(vector<int>& s, int i, vector<int> &dp){
        if(i >= s.size()){
            return 0;
        }

        int result = INT_MIN;
        if(dp[i] != -1){
            return dp[i];
        }
        result = max(result, s[i] -solveMem(s, i+1,dp));
        if(i+1<s.size())
        result = max(result, (s[i] + s[i+1] - solveMem(s,i+2,dp)));
        if(i+2<s.size())
        result = max(result, (s[i] + s[i+1] + s[i+2] - solveMem(s,i+3,dp)));
        dp[i] = result;
        return dp[i];
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int i=0;
        vector<int> dp(stoneValue.size()+1, -1);
        int ans = solveMem(stoneValue,i,dp);

        if(ans<0){
            return "Bob";
        }
        else if(ans>0){
            return "Alice";
        }
        return "Tie";
    }
};