class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxP = INT_MIN;
        int currentMax = nums[0];
        int i=1;
        while(i<nums.size()){
            maxP = max(maxP,(currentMax-1)*(nums[i]-1));
            currentMax = max(currentMax,nums[i]);
            i++;
        }
        return maxP;

    }
};