class Solution {
public:
    int reverseDegree(string s) {
        
        unsigned ans = 0;
        int pos = 1;
        char a='z';
    

        for(char &ch:s){
            int val = a - ch +1;
            ans +=  val*pos;
            pos++;
        }
        return ans;
    }
};