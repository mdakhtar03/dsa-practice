class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size()-1;
        
        int index = -1;
        for( int i = n ; i>=1 ; i--){
            if(nums[i-1]<nums[i]){
                index = i-1;
                break;
            }
        }
        
        if(index != -1){
            for( int i = n ;i>=index+1;i--){
            if(nums[i]>nums[index]){
                swap(nums[i],nums[index]);
                break;
            }
        }
        }


        reverse(nums.begin()+index+1, nums.end());


    }
};