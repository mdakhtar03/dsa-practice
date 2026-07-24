class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(), prices.end());

        int i=0,j=prices.size()-1;

        int firstChoco = prices[0];
        int secondChoco = prices[1];

        if(money - firstChoco - secondChoco < 0){
            return money;
        }

        return money - firstChoco - secondChoco;
        
    }
};