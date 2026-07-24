class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        //maxProductDiff = maxProduct - minProduct

        int currMax = nums[0];
        int maxProduct = 0;

        for(int i=1; i<nums.size();i++){
            maxProduct = max(maxProduct,currMax*nums[i]);
            currMax = max(currMax,nums[i]);
        }

        int currMin = nums[0];
        int minProduct = INT_MAX;

        for(int i=1; i<nums.size();i++){
            minProduct = min(minProduct,currMin*nums[i]);
            currMin = min(currMin,nums[i]);
        }
        
        return maxProduct - minProduct;
    }
};