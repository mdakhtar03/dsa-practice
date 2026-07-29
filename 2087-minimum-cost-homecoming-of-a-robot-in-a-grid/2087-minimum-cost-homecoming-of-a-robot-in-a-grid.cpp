class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int X1 = startPos[0];
        int X2 = homePos[0];
        int ans = 0;
        if(X1<X2){
            while(X1 != X2){
                X1++;
                ans += rowCosts[X1];
            }
        }
        else{
            while(X1 != X2){
                X1--;
                ans += rowCosts[X1];
            }
        }

        int Y1 = startPos[1];
        int Y2 = homePos[1];

        if(Y1<Y2){
            while(Y1 != Y2){
                Y1++;
                ans += colCosts[Y1];
            }
        }
        else{
            while(Y1 != Y2){
                Y1--;
                ans += colCosts[Y1];
            }
        }
        return ans;

    }
};