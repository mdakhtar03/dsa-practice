class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        //trying to find to min num;
        int min1=INT_MAX,min2 = INT_MAX;
        for(int i=0; i<prices.size();i++){
            if(min1>prices[i]){
                min2 = min1;
                min1 = prices[i];
            } else{
                min2 = min(prices[i], min2);
            }
        }
        if(money - min1- min2<0) return money;

        return money-min1-min2;
    }
};