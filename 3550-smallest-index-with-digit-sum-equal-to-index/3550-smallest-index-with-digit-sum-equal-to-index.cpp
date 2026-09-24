class Solution {
public:
    int smallestIndex(vector<int>& nums) {

        for(int i=0; i<nums.size();i++){
            int digit = nums[i];
            int sum = 0;
            while(digit){
                int ldig = digit%10;
                sum += ldig;
                digit /= 10;
            }
            if(sum == i){
                return i;
            }
        }
        return -1;
    }
};