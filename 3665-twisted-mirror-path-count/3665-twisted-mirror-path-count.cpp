class Solution {
public:
    using ll = long long;

    ll mod = 1e9 + 7;
    int m, n;

    int solveUsingMem(int i, int j, int dir, vector<vector<int>>& grid, vector<vector<vector<ll>>> &dp){
        if(i>=m || j>=n){
            return 0;
        }
        if (dp[i][j][dir] != -1)
            return dp[i][j][dir];

        if(i == m-1 && j == n-1){
            return 1;
        }

        if(grid[i][j] == 1){
            if(dir == 0){
                dp[i][j][dir] =  solveUsingMem(i+1, j, 1,grid,dp);
                return dp[i][j][dir];
            }
            else 
            {
                dp[i][j][dir] = solveUsingMem(i, j + 1, 0,grid,dp);
                return dp[i][j][dir];
            }
        }

     dp[i][j][dir]  =  (solveUsingMem(i, j + 1, 0,grid,dp)+ solveUsingMem(i + 1, j, 1,grid,dp))%mod;
    return dp[i][j][dir];
    }

    int solve(int i, int j, int dir, vector<vector<int>>& grid){
        if(i>=m || j>=n){
            return 0;
        }

        if(i == m-1 && j == n-1){
            return 1;
        }

        if(grid[i][j] == 1){
            if(dir == 0){
                return solve(i+1, j, 1,grid);
            }
            else 
            {
            return solve(i, j + 1, 0,grid);
            }
        }

    return solve(i, j + 1, 0,grid)
         + solve(i + 1, j, 1,grid);

    }

    int uniquePaths(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        if(m==1 && n==1){
            return 1;
        }
        vector<vector<vector<ll>>> dp(m,vector<vector<ll>>(n, vector<ll>(2, -1)));
        int dir = 0;
               //right movement         // left movement
         ll ans = solveUsingMem(0, 1, 0, grid, dp) + solveUsingMem(1, 0, 1, grid, dp);

        return (ans%mod);
    }
};