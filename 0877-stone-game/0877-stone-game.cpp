class Solution {
public:
    int solve(vector<int>& piles, int i, int j){
        if(i>j){
            return 0;
        }
        if(i==j){
            return piles[i];
        }

        int take_i = piles[i] + min(solve(piles,i+2,j), solve(piles,i+1,j-1));
        int take_j = piles[j] + min(solve(piles,i,j-1), solve(piles,i+1,j));
        return max(take_i, take_j);
    }
    int solveUsingMem(vector<int>& piles, int i, int j,vector<vector<int>> &dp ){
        if(i>j){
            return 0;
        }
        if(i==j){
            return piles[i];
        }
        if(dp[i][j] != 0){
            return dp[i][j];
        }

        int take_i = piles[i] + min(solveUsingMem(piles,i+2,j,dp), solveUsingMem(piles,i+1,j-1,dp));
        int take_j = piles[j] + min(solveUsingMem(piles,i,j-1,dp), solveUsingMem(piles,i+1,j,dp));
        dp[i][j] = max(take_i, take_j);
        return max(take_i, take_j);
    }
    bool stoneGame(vector<int>& piles) {
        int sumOfpiles = 0;
        int size = piles.size()+1;
        vector<vector<int>> dp(size,vector<int>(size, 0));
        for(int &pile:piles){
            sumOfpiles += pile;
        }
        int i=0,j=piles.size();
        int Alice = solveUsingMem(piles,i,j-1,dp);
        int Bob =sumOfpiles-Alice;
        return Alice>Bob;
    }
};