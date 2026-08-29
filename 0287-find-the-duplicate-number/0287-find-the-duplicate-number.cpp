class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //Slow and fast Pointer

        int slow = 0,fast = 0;

        while(true){
            slow = nums[slow];

            fast = nums[fast];
            fast = nums[fast];
            if(nums[slow] == nums[fast]) break;
        }

        slow = 0;
        while(nums[slow] != nums[fast]){
            slow = nums[slow];
            fast = nums[fast];
        }
        return nums[slow];
    }
};