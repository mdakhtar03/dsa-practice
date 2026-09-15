class Solution {
  public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        // code here
        set<int> st;
        
        for( int &num:a){
            st.insert(num);
        }
        
        for( int &num:b){
            st.insert(num);
        }
        vector<int> ans;
        for(auto it:st){
            ans.push_back(it);
        }
        return ans;
    }
};