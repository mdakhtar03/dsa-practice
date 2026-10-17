class Solution {
public:

    int digitSum(int num){
        int sum=0;
        while(num){
            int rem = num%10;
            sum += rem;
            num /= 10;
        }
        return sum;
    }
    

    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        vector<int> sortedNums = nums;

        auto comp =[this](int num1, int num2){
            int dSum1 = digitSum(num1);
            int dSum2 = digitSum(num2);

            if(dSum1 != dSum2)
                return dSum1<dSum2;
            
            return num1<num2;

        };

        
        sort(sortedNums.begin(), sortedNums.end(), comp);

        unordered_map<int, int> mp;

        for(int i=0; i<n ;i++){
            mp[nums[i]] = i;
        }

        int swapCount = 0;

        for(int i=0 ;i<nums.size() ;i++){
            int expectedVal = sortedNums[i];
            int currentVal = nums[i];

            if(expectedVal != currentVal){
                nums[i]  = expectedVal;
                int index = mp[expectedVal];
                nums[index] = currentVal;
                mp[currentVal] = index;
                swapCount++;
            }

        }
        return swapCount;
    }
};