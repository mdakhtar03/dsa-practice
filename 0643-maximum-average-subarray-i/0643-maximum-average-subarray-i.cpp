class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double maxSum = INT_MIN;
        double sum=0;
        for(int i=0; i<k; i++){
            double element = nums[i];
            sum += element;
        }

        maxSum = max(maxSum,sum);

        for( int i=k; i<nums.size() ; i++){
           sum = sum - nums[i-k]+nums[i];
           maxSum = max(sum, maxSum);
        }
        return double(maxSum/k);
    }
};