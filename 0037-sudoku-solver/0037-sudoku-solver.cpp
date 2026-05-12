class Solution {
public:
    bool isCellEmpty(vector<vector<char>>& board, int &row, int &col){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j] == '.'){
                    row = i;
                    col = j;
                    return true;
                }
            }
        }
        return false;
    }

    bool isSafe(vector<vector<char>>& board, int &row, int &col, char num){
        // Checking Column Wise
            for(int j=0;j<9;j++){
                if(board[row][j] == num){
                    return false;
                }
            }
        // Checking Row Wise
            for(int i=0;i<9;i++){
                if(board[i][col] == num){
                    return false;
                }
            }
        // Checking Sub Grid

            int startRow = row - (row%3);
            int startCol = col - (col%3);
            for(int i=0 ;i <3 ;i++){
                for(int j=0 ; j<3; j++){
                    int r= i + startRow;
                    int c= j+startCol;
                    if(board[r][c] == num){
                        return false;
                    }
                }
            }

        return true;
    }




    bool solve(vector<vector<char>>& board){
       //  need to find empty cell
        int row,col;
        if(!isCellEmpty(board,row,col)){
            return true;
        }
        for(int i=1;i<=9;i++){
            char num = i + '0';
            if(isSafe(board,row,col,num)){
                board[row][col]=num;
                if(solve(board)){
                    return true;
                }
                board[row][col] = '.';
            }
        }

       return false; 

    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
}; 