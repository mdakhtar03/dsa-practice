class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int minDistance = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                for (int  k = j + 1; k < nums.size(); k++) {
                    if (nums[i] == nums[j] && nums[j] == nums[k]) {
                        if (minDistance >
                            abs(i - j) + abs(j - k) + abs(k - i)) {
                            minDistance = abs(i - j) + abs(j - k) + abs(k - i);
                        }
                    }
                }
            }
        }
        return minDistance==INT_MAX? -1:minDistance ;
    }
};