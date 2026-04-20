class Solution {
public:
    bool isUgly(int n) {
        if (n <= 0) {
            return false;
        }
        if((n&(n-1)) == 0){
            return true;
        }
       

        while(n != 1){
            if((n&1) == 0){
               n=n/2;
            }
            else if((n%3) ==0){
                n=n/3;
            }
            else if((n%5) ==0){
                n=n/5;
            }
            else{
                return false;
            }
        }
        return true;
    }
};