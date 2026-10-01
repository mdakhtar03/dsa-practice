class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n = s.size();
        if(n&1){
            return false;
        }

        for(char &ch:s){
            if(ch == '(' || ch == '[' || ch == '{'){
                st.push(ch);
            }
            else if(!st.empty() && ch == ')'){
                if(st.top() == '('){
                    st.pop();
                }
                else{
                    return false;
                }
            }
            else if( !st.empty() && ch == '}' ){
                if(st.top() == '{'){
                    st.pop();
                }
                else{
                    return false;
                }
            }
            else{
                if(!st.empty() && st.top() == '[' ){
                    st.pop();
                }
                else{
                    return false;
                }
            }
        }

        if(st.empty()){
            return true;
        }
        return false;
    }
};