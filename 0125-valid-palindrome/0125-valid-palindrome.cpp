class Solution {
public:
    bool isPalindrome(string s) {
        string ans="";
        for( auto &ch:s){
            if(ch >= 'A' && ch<= 'Z'){
                ans.push_back(ch-'A'+'a');
            }
            else if(ch>='a' && ch<='z'){
                ans.push_back(ch);
            }
            else if(ch >= '0' && ch <= '9'){
                ans.push_back(ch);
            }
        }
        int i=0,j=ans.size()-1;
        while(i<=j){
            if(ans[i] != ans[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};