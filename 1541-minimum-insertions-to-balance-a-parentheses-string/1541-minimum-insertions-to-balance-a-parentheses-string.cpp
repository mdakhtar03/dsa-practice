class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        stack<char> st;
        int ans = 0;
        int openCount=0;
        for(int i=0; i<s.length();){
            if(s[i] == '('){
                openCount++;
                i++;
            }
           
            else {
                 
                if(openCount>0){
                    openCount--;
                }
                else{
                    ans++;
                }
                if(i+1 < n && s[i+1] == ')'){
                    i += 2;
                }
                else{
                    ans++;
                    i++;
                }
            }

        }
            if(openCount != 0){
                ans += openCount*2;
            }
            return ans;
    }
};