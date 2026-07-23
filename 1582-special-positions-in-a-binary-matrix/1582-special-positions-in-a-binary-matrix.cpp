class Solution {
public:
    bool checker(vector<vector<int>>& mat, int row, int col){
        //horizontal Check
        int horizontalCheck = row;
        for(int i=0;i<mat[0].size();i++){
            if(i == col){
                continue;
            }
            else if(mat[row][i] != 0){
                return false;
            }
        }
        //vertical Check
        int verticalCheck = col;
        for(int i=0; i<mat.size();i++){
            if(row ==i){
                continue;
            }
            else if(mat[i][col] != 0){
                return false;
            }
        }
        return true;
    }
    int numSpecial(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        int ans = 0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(mat[i][j] == 1){

                    if(checker(mat,i,j)){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};