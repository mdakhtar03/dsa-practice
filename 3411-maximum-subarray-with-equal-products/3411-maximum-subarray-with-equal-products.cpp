#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 1; 
        unsigned long long maxPossible = 1;
        for (int x : nums) {
            maxPossible = lcm(maxPossible, (unsigned long long)x);
        }
        
        unsigned long long maxElement = *max_element(nums.begin(), nums.end());
        unsigned long long limit = maxPossible * maxElement;

        for (int i = 0; i < n; ++i) {
            unsigned long long prod = 1;
            unsigned long long currentGcd = 0;
            unsigned long long currentLcm = 1;

            for (int j = i; j < n; ++j) {
                
                if (prod > limit / nums[j]) {
                    break;
                }
                
                prod *= nums[j];
                currentGcd = gcd(currentGcd, (unsigned long long)nums[j]);
                currentLcm = lcm(currentLcm, (unsigned long long)nums[j]);

                if (prod == currentLcm * currentGcd) {
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }

        return maxLen;
    }
};
