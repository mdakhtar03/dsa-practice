class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        long long ans = 0;
        long long cost = 0;
        deque<int> dq;
        int n = nums.size();
        int j = n - 1;

        for (int i = n - 1; i >= 0; --i) {
            // Maintain a monotonic decreasing queue of indices within [i, j]
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                int l = dq.back();
                dq.pop_back();
                // Use j + 1 instead of n as the right boundary of the current window
                int r = dq.empty() ? j + 1 : dq.back();
                cost += (long long)(r - l) * (nums[i] - nums[l]);
            }
            dq.push_back(i);

            // Shrink the window from the right if cost exceeds k
            while (cost > k) {
                cost -= nums[dq.front()] - nums[j];
                if (dq.front() == j) {
                    dq.pop_front();
                }
                j--;
            }

            ans += (j - i + 1);
        }

        return ans;
    }
};