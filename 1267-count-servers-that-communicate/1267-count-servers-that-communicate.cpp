class Solution {
public:
    int row,col;
    bool rowWise(vector<vector<int>>& grid,int i,int j){
       
       for(int col=0; col<grid[i].size();col++){
        if(col == j) continue;
        if(grid[i][col] == 1){
            return true;
        }
       }
    return false;

    }

    bool colWise(vector<vector<int>>& grid,int i,int j){
        
        for(int row = 0 ; row<grid.size(); row++){
            if(row==i) continue;
            if(grid[row][j]==1){
                return true;
            }
        }

        return false;

    }
    int countServers(vector<vector<int>>& grid) {
        int count = 0;
        row = grid.size();
        col = grid[0].size();
        for(int i=0; i<row; i++){
            for(int j = 0; j<col;j++){
                if(grid[i][j] == 1 && (rowWise(grid,i,j) || colWise(grid,i,j))){
                    count++;
                }
            }
        }
        return count;
    }
};