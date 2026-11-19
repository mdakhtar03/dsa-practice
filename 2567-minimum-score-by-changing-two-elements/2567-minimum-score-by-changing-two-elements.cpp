class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        
        int num1 = nums[n-2]-nums[1];

        int num2 = nums[n-3]-nums[0];

        int num3 = nums[n-1]-nums[2];

        return min(num1, min(num2,num3));
        
    }
};