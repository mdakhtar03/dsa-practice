class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pasTri;
        vector<int> Ones;

        for(int i = 0 ; i < numRows ; i++){
            for(int j = 0 ; j < i+1 ; j++ ){
                Ones.push_back(1);
            }
            pasTri.push_back(Ones);
            Ones.clear();
        }
        for(int i=2 ; i<numRows ; i++){

            for(int j=1 ; j<i ; j++){
                
                    int previousRow = i - 1;
                    int previousCol =  j - 1;
                    int num1 = pasTri[previousRow][j];
                    int num2 =   pasTri[previousRow][previousCol];
                    pasTri[i][j] = num1 + num2;
                
                
            }
        }

        return pasTri;
    
    }
};