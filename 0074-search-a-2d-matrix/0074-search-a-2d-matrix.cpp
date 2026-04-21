class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows=matrix.size();
        int cols= matrix[0].size();
        int totalElement = rows*cols;
        int s=0, e=totalElement-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            
            int rowIndex=mid/cols;
            int colIndex=mid%cols;

            if(matrix[rowIndex][colIndex]==target){
                return true;
            }
            else if(matrix[rowIndex][colIndex]>target){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return 0;
    }
};