class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int row=0;row<matrix.size();row++){
            for(int col=row; col<matrix[0].size();col++){
                swap(matrix[row][col],matrix[col][row]);
            }
        }
        
         for(int i=0;i<matrix.size();i++)
        {
            int row=matrix[i].size()-1;
          
            for(int j=0;j<=row;)
            {
                swap(matrix[i][j],matrix[i][row]);
                row--;
                j++;
            }
        }

        
    }
};