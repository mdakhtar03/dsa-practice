class Solution {
public:
    string largestOddNumber(string num) {
        string ans = num;
        char ch = ans.back();
        int lastDigit = ch-'0';
        while( !ans.empty()){
            if(lastDigit&1){
                break;
            }
            
            ans.pop_back();
            if(!ans.empty()){

                ch = ans.back();
                lastDigit = ch -'0';
            }
        }
        return ans;
    }
};