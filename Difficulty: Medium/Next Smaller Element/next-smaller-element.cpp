class Solution {
  public:
    vector<int> nextSmallerEle(vector<int>& arr) {
        int n=arr.size()-1;
        stack<int> st;
        st.push(-1);
        for(int i=n;i>=0;i--){
            while(st.top() >= arr[i]){
                st.pop();
            }
            int element = arr[i];
            arr[i] = st.top();
            st.push(element);
        }
        return arr;
    }
};