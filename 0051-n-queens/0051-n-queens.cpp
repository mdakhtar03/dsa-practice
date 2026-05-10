class Solution {
public:
    bool canPlace(vector<vector<char>> &board,int row, int col ){
        //move backward till col zero
        for(int i=col; i>=0; i--){
            if(board[row][i] == 'Q'){
                return false;
            }
        }
        //move diagonally downwards
        int i = row;
        int j= col; 
            while(i<board.size() && j>=0){
                if(board[i][j] == 'Q'){
                    return false;
                }
                i++;
                j--;
            }
        //move diagonally upwards
        i=row;
        j=col;
        while(i>=0 && j>=0){
            if(board[i][j] == 'Q'){
                return false;
            }
            i--;
            j--;
        }
        return true;
    }

    void storeAns(vector<vector<char>> &board, vector<vector<string>>& ans){
        vector<string> temp;
        for(int i=0;i<board.size();i++){
            string output = "";
            for(int j=0;j<board[i].size();j++){
                char ch  = board[i][j];
                output.push_back(ch);
            }
            temp.push_back(output);
        }
        ans.push_back(temp);
    }

    void solve(vector<vector<char>> &board, vector<vector<string>>& ans, int row, int col ){
        if(col>=board[0].size()){
            storeAns(board,ans);
            return;
        }
        //place queem
        for(int row=0;row<board.size();row++){
            if(canPlace(board,row,col)){
                //Place the Queen
                board[row][col] = 'Q';
                //Call for next col to place
                solve(board, ans, row, col+1);
                //Backtrack
                board[row][col] = '.';
            }

        }
    }

    vector<vector<string>> solveNQueens(int n) {
      vector<vector<char>> board(n, vector<char>(n,'.'));
        vector<vector<string>> ans;
        solve(board,ans,0,0); 
        return ans;
    }
};