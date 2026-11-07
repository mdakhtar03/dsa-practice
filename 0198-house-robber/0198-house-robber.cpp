class Solution {
public:
    
    int solveMem(vector<int>& nums, int i,vector<int> &dp){
        if(i>=nums.size()) return 0;

        if(dp[i] != -1){
            return dp[i];
        }


        //Include
       
        
        int currentHouse = nums[i] + solveMem(nums, i+2,dp);
        //Exclude
        int nextHouse = solveMem(nums, i+1,dp);
        dp[i]=max(currentHouse,nextHouse);
        return max(currentHouse,nextHouse);

    }
    int rob(vector<int>& nums) {
        unsigned int sum = 0;
        vector<int> dp(nums.size()+1, -1);
        return solveMem(nums,0,dp);
    }
};