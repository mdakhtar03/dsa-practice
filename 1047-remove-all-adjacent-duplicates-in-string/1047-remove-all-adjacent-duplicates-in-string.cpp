class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        st.push(s[0]);
        for(int i=1;i<s.size();i++){
            if(!st.empty()){
                if(st.top()!=s[i]){
                    st.push(s[i]);
                }
                else{
                    st.pop();
                    if(st.empty()){
                        if(i+1<s.size()){
                        ++i;
                        st.push(s[i]);
                        }
                    }
                }
            }
        }
        string ans="";
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        //reverse 
        
        int i=0,j=ans.size()-1;
        while(i<j){
            swap(ans[i],ans[j]);
            i++;
            j--;
        }
        return ans;
    }
};