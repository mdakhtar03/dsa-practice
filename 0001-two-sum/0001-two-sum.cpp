class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {
            int need = target - nums[i];

            if (mp.count(need)){
                ans.push_back(mp[need]);
                ans.push_back(i);
                break;
                }

                

            mp[nums[i]] = i;
        }
        return ans;
    }
};