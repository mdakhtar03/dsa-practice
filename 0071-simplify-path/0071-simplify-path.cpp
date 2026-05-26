class Solution {
public:
    void reverseAns(string &ans, stack<string> &st){
        if(st.empty()){
            return;
        }
        string temp = st.top();
        st.pop();
        reverseAns(ans,st);
        ans += temp;
    }



    string simplifyPath(string path) {
        stack<string> st;
        int i=0;
        while(i<path.size()){
            int start = i;
            int end = i+1;
            for( end; path[end] != '/' && end<path.size();end++){}
            string minPath = path.substr(start, end-start);
            i=end;
            if(minPath == "/"|| minPath == "/."){
                continue;
            }
            if(minPath != "/.."){
                st.push(minPath);
            }
            else {
                if(!st.empty()){
                    st.pop();
                }
            }
        }
        string ans="";
        if(st.empty()){
            ans = "/";
            return ans;
        }

        //reverse ans
        reverseAns(ans,st);
        return ans;
    }
};