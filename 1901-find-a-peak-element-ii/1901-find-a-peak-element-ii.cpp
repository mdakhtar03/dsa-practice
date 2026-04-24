class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int s=0,e=mat[0].size()-1;
        int rows=mat.size();
        int cols=mat[0].size();
        int maxVal=INT_MIN;
        vector<int> maxIndex;
        while(s<=e){
            int mid = (s+e)/2;
            maxVal=INT_MIN;
            for(int i=0;i<rows;i++){
                if(maxVal<mat[i][mid]){
                    maxVal=mat[i][mid];
                    maxIndex.clear();
                    maxIndex.push_back(i);
                    maxIndex.push_back(mid);
                }
            }
            int i=maxIndex[0];
            int j=maxIndex[1];
            if( j+1<cols && mat[i][j]<mat[i][j+1]){
                s=mid+1;
            }
            else if(j-1>=0 && mat[i][j]<mat[i][j-1]){
                e=mid-1;
            }
            else {
                return maxIndex;
            }
            
        }
        return maxIndex;

    }
};