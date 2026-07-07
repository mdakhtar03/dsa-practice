class Solution {
public:
    long long sumAndMultiply(int n) {
        long long num=0,sum=0;
        int quotient=0, remainder = 0;
        while(n){
            remainder = n%10;
            sum += remainder;
            if(remainder){
                num = num*10+ remainder;
            }
            n /= 10;
        }
        long long ans=0;
        //reverse
        while(num){
            remainder = num%10;
            ans = ans*10+ remainder;
            num /= 10;
        }
        return ans*sum;
    }
};