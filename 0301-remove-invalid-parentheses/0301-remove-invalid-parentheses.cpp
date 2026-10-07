class Solution {
public:

    void solve(int i, int &n, string &s, string &curr, int count, 
    unordered_set<string> &st, int &maxLen){
        if(count<0){
            return;
        }
        if(i == n){
            if(count == 0){
                if(curr.length()>maxLen){
                    st.clear();
                    maxLen = curr.length();
                }
                if(maxLen == curr.size()){
                    st.insert(curr);
                }
            }
            return;
        }
        if(s[i] != '(' && s[i] != ')'){
            curr.push_back(s[i]);
            solve(i+1, n, s, curr, count, st, maxLen);
            curr.pop_back();
            return;
        }
        curr.push_back(s[i]);
        solve(i+1, n, s, curr, count + (s[i] == '(' ? 1 :-1), st, maxLen);
        curr.pop_back();
        solve(i+1, n, s, curr,count, st, maxLen);
    }

    vector<string> removeInvalidParentheses(string s) {
        int n= s.size();
        unordered_set<string> st;
        string curr = "";
        int maxLen=0;
        solve(0,n, s, curr,0,st, maxLen);

        return vector<string> (begin(st),end(st));
    }
};