class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans;
        while(columnNumber){
            columnNumber--;
            int rem = columnNumber%26;
            char ch = rem + 'A' ;

            ans.push_back(ch);
            columnNumber=columnNumber/26;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};