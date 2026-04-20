class Solution {
public:
    bool isPalindrome(int x) {
        int copy=x;
        if(copy<0){
            return 0;
        }
        long ans=0,remainder;
        while(copy){
            remainder = copy%10;
            ans=ans*10+remainder;
            copy=copy/10;
        }
        return ans==x? 1:0;
    }
};