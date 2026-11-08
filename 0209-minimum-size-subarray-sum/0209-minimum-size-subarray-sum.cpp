class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        deque<int> dq;

        int sum = 0;
        int ans = INT_MAX;

        for(int j = 0; j < nums.size(); j++) {

            // Expand window
            dq.push_back(nums[j]);
            sum += nums[j];

            // Shrink window
            while(sum >= target) {

                ans = min(ans, (int)dq.size());

                sum -= dq.front();
                dq.pop_front();
            }
        }

        return ans == INT_MAX ? 0 : ans;
    }
};