class Solution {
  public:
    int countMinReversals(string s) {
        stack<char> st;
        int count=0;
        for(char &ch:s){
            count++;
        }
        if((count&1)==1){
            return -1;
        }
        
        for(char &ch:s){
            if(st.empty()){
                st.push(ch);
            }
            else if(ch == '}' && st.top() == '{'){
                st.pop();
            }
            else {
                st.push(ch);
            }
        }
        
        count=0;
        
        while(!st.empty()){
            char ch1 = st.top();
            st.pop();
            char ch2 = st.top();
            st.pop();
            if(ch1 == ch2){
                count += 1;
            }
            else {
                count +=2;
            }
        }
        
        return count;
        
        
    }
};