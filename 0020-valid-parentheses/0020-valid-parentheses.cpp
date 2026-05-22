class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        if(s.size()%2 == 1){
            return false;
        }
        for(char ch:s){
            if(ch == '(' || ch == '{' || ch == '['){
                st.push(ch);
            }
            else if(ch == ')'){
                if(!st.empty()){

                if(st.top() == '('){
                    if(!st.empty())
                    st.pop();
                }
                else{
                    return false;
                }
                }
                else{
                    return false;
                }
            }
            else if(ch == '}'){
                if(!st.empty()){

                if(st.top() == '{'){
                    if(!st.empty())
                    st.pop();
                }
                else{
                    return false;
                }
                }
                else{
                    return false;
                }
            }
            else if(ch == ']'){
                if(!st.empty()){
                if(st.top() == '['){
                    if(!st.empty())
                    st.pop();
                }
                else{
                    return false;
                }
                }
                else {
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