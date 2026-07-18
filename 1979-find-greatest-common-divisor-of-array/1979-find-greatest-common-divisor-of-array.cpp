class Solution {
public:
    int findGCD(vector<int>& nums) {
        int min=INT_MAX,max=INT_MIN;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]<min){
                min=nums[i];
            }
            if(nums[i]>max){
                max=nums[i];
            }
        }
        //GCD
        int remainder, ans;
        while(min != 0){
           remainder = max%min;
           max=min;
           min=remainder;
        }
        return max;
    }
};