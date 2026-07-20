class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        if(k==0) return grid;
        vector<int> copy;
        for(int i=0; i<grid.size();i++){
            for(int j=0; j<grid[0].size();j++){
                copy.push_back(grid[i][j]);
            }
        }
        //rotate
        k = k%copy.size();
        reverse(copy.begin(),copy.end());
        reverse(copy.begin(),copy.begin()+k);
        reverse(copy.begin()+k,copy.end());
        int p=0;
        for(int i=0; i<grid.size();i++){
            for(int j=0; j<grid[0].size();j++){
                grid[i][j] = copy[p];
                p++;
            }
        
        }
        return grid;
    }
};