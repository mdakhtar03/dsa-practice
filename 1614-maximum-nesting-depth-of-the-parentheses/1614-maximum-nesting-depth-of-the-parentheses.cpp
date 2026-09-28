class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        stack<char> st;
        for(char &ch:s){
            if(ch == '('){
                st.push('(');
            }
            else if(ch == ')'){
                st.pop();
            }
            int n = st.size();
            ans = max(ans,n);
        }
        return ans;
    }
};