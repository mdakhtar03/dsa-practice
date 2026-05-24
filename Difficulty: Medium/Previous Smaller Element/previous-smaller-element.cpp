class Solution {
  public:
    vector<int> prevSmaller(vector<int>& arr) {
        stack<int> st;
        st.push(-1);
        int element = -1;
        for(int i=0;i<arr.size();i++){
            while(st.top() >= arr[i]){
                st.pop();
            }
            element = arr[i];
            arr[i] = st.top();
            st.push(element);
        }
        return arr;
    }
    
};