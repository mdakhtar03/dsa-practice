class Solution {
public:
    int row,col;

    bool found(vector<vector<int>>& grid, int i, int j){
        

        if( i<0 ||  i>=row || j<0 || j>=col){
            return false;
        }

        if(grid[i][j] == 1){
            return true;
        }

        grid[i][j] = 1;

        int up = found(grid,i+1,j);
        int down = found(grid,i-1,j);
        int left = found(grid,i,j-1);
        int right = found(grid,i,j+1);

        return up && down && left && right;

    }

    int closedIsland(vector<vector<int>>& grid) {
        row = grid.size();
        col = grid[0].size();
        int count=0;
        for(int i=0; i<row; i++){
            for(int j=0;j<col;j++){
                if(grid[i][j] == 0){
                    if(found(grid, i, j)){
                    count++;
                    }
                }
                
            }
        }
        return count;
    }
};