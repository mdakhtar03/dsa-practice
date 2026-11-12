class Solution {
public:
    int strictly_increasing_SubArray(vector<int>& nums){
        int n = nums.size();
        int len = 1;
        int ans = 1;
        for(int i=1; i<n ; i++){
            if(nums[i-1] < nums[i]){
                len++;
                ans = max(ans,len);
            }
            else{
                len = 1;
            }
        }

    return ans;
    }

    int strictly_decreasing_SubArray(vector<int>& nums){
        int n = nums.size();
        int len = 1;
        int ans = 1;
        for(int i=1; i<n ; i++){
            if(nums[i-1] > nums[i]){
                len++;
                ans = max(ans,len);
            }
            else{
                len = 1;
            }
        }

    return ans;
    }
    int longestMonotonicSubarray(vector<int>& nums) {
        return max(strictly_increasing_SubArray(nums), strictly_decreasing_SubArray(nums));
    }
};