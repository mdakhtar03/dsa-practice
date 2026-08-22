class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int product = 1;
        int cp=n;
        while(cp){
            sum += cp%10;
            product *= cp%10;
            cp = cp/10;
        }
        int number = sum + product;
        if(n%number == 0){
            return true;
        }
        return false;
    }
};