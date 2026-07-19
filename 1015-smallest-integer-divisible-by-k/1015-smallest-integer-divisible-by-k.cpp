class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if((k&1)==0 || (k %5==0)){
            return -1;
        }

        int count = 0;
        int remainder = k;
        while(remainder){
            count++;
            remainder = ((remainder*10)+1)%k;
        }
        return count;
    
    }
};