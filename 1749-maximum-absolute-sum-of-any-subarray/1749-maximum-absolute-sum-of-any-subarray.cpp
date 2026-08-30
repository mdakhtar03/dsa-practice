class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        //Max Sub Array using Kadane's Algo
        int currSum = nums[0];
        int maxSum = nums[0];

        int minSum = nums[0];

        for(int i=1 ; i<nums.size() ; i++){
            if(currSum + nums[i]>nums[i]){
                currSum += nums[i];
            }
            else{
                currSum = nums[i];
            }
            maxSum = max(currSum,maxSum);
        }
        currSum = nums[0];
        for(int i=1 ; i<nums.size() ; i++){
            if(currSum + nums[i] < nums[i]){
                currSum += nums[i];
            }
            else{
                currSum = nums[i];
            }
            minSum = min(currSum,minSum);
        }

        return max(maxSum , abs(minSum));
        
    }
};