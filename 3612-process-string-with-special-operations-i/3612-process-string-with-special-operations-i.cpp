class Solution {
public:
    string processStr(string s) {
        string ans;
        for(int i=0;i<s.size();i++){
            char ch = s[i];
            if(ch == '*'){
                if(ans.size()>0){
                    ans.pop_back();
                }
            }
                else if(ch == '%'){
                    reverse(ans.begin(),ans.end());
                }
                else if(ch == '#'){
                   string temp = ans;
                    ans = ans +temp;
                }
                else{
                    ans.push_back(ch);
                }
        }
        return ans;
    }
};