class Solution {
public:
    
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        
        long long totalSubarrays = 0;
        int currentSum = 0;
        
        // An empty prefix has a sum of 0, which is even
        int evenCount = 1; 
        int oddCount = 0;
        
        for (int num : arr) {
            currentSum += num;
            
            if (currentSum % 2 != 0) {
                // Current prefix sum is odd; pair it with previous even prefix sums
                totalSubarrays = (totalSubarrays + evenCount) % MOD;
                oddCount++;
            } else {
                // Current prefix sum is even; pair it with previous odd prefix sums
                totalSubarrays = (totalSubarrays + oddCount) % MOD;
                evenCount++;
            }
        }
        
        return totalSubarrays;
    }
};