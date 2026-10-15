class Solution {
public:
    int sumCounts(vector<int>& nums) {
        unordered_set<int> st;
        unsigned int ans = 0;
        int n = nums.size();
        for (int k = 0; k < n; k++) {
            for (int i = k; i < n; i++) {
                for (int j = k; j <= i; j++) {
                    st.insert(nums[j]);
                }
                int count = st.size();
                st.clear();
                ans += count * count;
            }
        }
        return ans;
    }
};