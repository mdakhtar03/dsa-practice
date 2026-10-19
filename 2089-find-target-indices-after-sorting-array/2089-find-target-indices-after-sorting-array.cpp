class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> ans;
        int count = 0;
        for(int &num:nums){
            if(num < target){
                count++;
            }
        }
        for(int j = 0 ; j<nums.size(); j++){
            if(nums[j] == target){
                ans.push_back(count);
                count++;
            }
        }
        return ans;
    }
};