class Solution {
public:
    int reverse(int x) {
        int number = abs(x);
        int ans=0,remainder;
        while(number){
            remainder = number % 10;
            if((ans>INT_MAX/10) ||(ans<INT_MIN/10)){
                return 0;
            }
            ans = ans*10 + remainder;
            number /=10;
        }
        if(x<0){
            return -ans;
        }
        return ans;
    }
};