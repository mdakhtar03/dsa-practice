class Solution {
public:
    string removeOuterParentheses(string s) {
        vector<string> decompse;
        int open = 0;
        string temp;
        string ans;
        int i=0;
        while(i<s.size()){
            if(s[i] == '('){
                open++;
                temp += s[i];
            }
            else if(s[i] == ')'){
                open--;
                temp += s[i];
            }

            if(open == 0){
                decompse.push_back(temp);
                temp="";
            }
            i++;
        }
        for(auto &deco:decompse){
            for(int i=1; i<deco.size()-1; i++){
                ans.push_back(deco[i]);
            }
        }
        return ans;
    }
};