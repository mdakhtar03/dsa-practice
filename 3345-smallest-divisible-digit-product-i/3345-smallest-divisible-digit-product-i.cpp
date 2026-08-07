class Solution {
public:
    bool checkTheNumber(int n, int t){
        int product=1;
        while(n){
            int rem = n%10;
            n = n/10;
            product *= rem;
        }
        if(product%t == 0){
            return true;
        }
        return false;
    }
    int smallestNumber(int n, int t) {
        while(n<n+10){
           bool ans = checkTheNumber(n,t);
           if(ans) break;

           n++;
        }

        return n++;
    }
};