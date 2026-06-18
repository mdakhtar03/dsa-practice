class Solution {
public:
    int solveUsingRec(vector<int> &nums, int index){
        if(index>=nums.size()){
            return 0;
        }
        
        int includeAns=nums[index]+solveUsingRec(nums,index+2);
        int excludeAns=0+solveUsingRec(nums,index+1);
        return max(includeAns,excludeAns);
    }
    
    int solveUsingMem(vector<int> &nums, int index, vector<int> &dp){
        if(index>=nums.size()){
            return 0;
        }
        if(dp[index] != -1){
            return dp[index];
        }
        
        int includeAns=nums[index]+solveUsingMem(nums,index+2,dp);
        int excludeAns=0+solveUsingMem(nums,index+1,dp);
        dp[index] = max(includeAns,excludeAns);
        return dp[index];
    }
    int rob(vector<int>& nums) {
        int index=0;
        vector<int> dp(nums.size()+1,-1);
        return solveUsingMem(nums,index,dp);

    }
};