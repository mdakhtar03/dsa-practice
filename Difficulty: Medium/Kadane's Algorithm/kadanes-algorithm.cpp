class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        // Code here
        int currSum = arr[0];
        
        int maxSubSum = currSum;
        
        for(int i=1; i<arr.size();i++){
            if(currSum + arr[i]>arr[i]){
                currSum += arr[i];
                maxSubSum = max(currSum,maxSubSum);
            }
            else{
                currSum=arr[i];
                maxSubSum = max(currSum,maxSubSum);
            }
        }
        return maxSubSum;
    }
};