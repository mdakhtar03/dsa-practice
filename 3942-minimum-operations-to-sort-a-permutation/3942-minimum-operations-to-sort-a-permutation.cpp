class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        int inc_count = 0;
        int dec_count = 0;

        for(int i=1; i<n; i++){
            if(nums[i] == (nums[i-1]+1)%n) {
                inc_count += 1;
            }

            if(nums[i-1] == (nums[i]+1)%n){
                dec_count += 1;
            }
        }

        if(inc_count == n-1 && nums[0] == 0) return 0;

        if(inc_count == n-1){
            int leftRotation = n - nums[0];
            int rightRotation = (nums.back()+1) + 2;
            return min(leftRotation, rightRotation);
        }

        if(dec_count == n-1){
            int leftRotation = n - nums.back()+1;
            int rightRotation = (nums[0] + 1 )%n +1;
            return min(leftRotation,rightRotation); 
        }

        return -1;

    }
};