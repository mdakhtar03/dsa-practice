class Solution {
public:
    char findTheDifference(string s, string t) {
        int sum=0;
        for(char &ch:t){
            int iAlpha = ch;
            sum += iAlpha;
        }
        for(char &ch:s){
            int iAlpha = ch;
            sum -= iAlpha;
        }
        
       
        return char(sum);

    }
};