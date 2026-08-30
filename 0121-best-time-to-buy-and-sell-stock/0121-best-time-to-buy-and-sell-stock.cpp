class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profitMax = 0;
        int i=0,j=1;

        while(j<prices.size()){
            if(prices[j]-prices[i] < 0){
                i=j;
            }
            else if(prices[j]-prices[i] >profitMax){
                profitMax = prices[j]-prices[i];
            }
            j++;
        }
        return profitMax;

    }
};