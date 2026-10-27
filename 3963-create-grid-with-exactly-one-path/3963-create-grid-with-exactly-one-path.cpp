class Solution {
public:
    
    vector<string> createGrid(int m, int n) {
        string firstRow(n,'.');
        string remaining = string(n-1, '#') + '.';
        vector<string> grid;
        grid.push_back(firstRow);
        for(int i=1; i<m;i++){

            grid.push_back(remaining); 

        }
        
        return grid;
    }
};