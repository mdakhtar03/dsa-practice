class Solution {
public:
    int row,col;
        long long solve(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i >= row || j >= col ) {
            return 0;
        }
        if(grid[i][j] == 0) return 0;

        // Store the value and mark this cell as visited.
        long long sum = grid[i][j];
        grid[i][j] = 0;


        sum += solve(grid, i + 1, j);
        sum += solve(grid, i - 1, j);
        sum += solve(grid, i, j + 1);
        sum += solve(grid, i, j - 1);

        return sum;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int count = 0;
        row = grid.size();
        col = grid[0].size();
        
        for(int i=0; i<row; i++){
           
            for(int j = 0; j<col ; j++){
                if(grid[i][j] != 0){
                    long long sum = solve(grid, i, j);
                    if(sum%k == 0){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};