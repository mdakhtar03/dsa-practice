class Solution {
public:
    int solve(vector<int>& nums, int i, int j){
        if(i>j){
            return 0;
        }
        if(i==j){
            return nums[i];
        }

        int take_i = nums[i] + min(solve(nums,i+2, j),solve(nums,i+1,j-1));

        int take_j = nums[j] + min(solve(nums,i,j-2), solve(nums,i+1, j-1));

        return max(take_i, take_j);
    }

    bool predictTheWinner(vector<int>& nums) {
        int toatalSum = 0;
        for(int &n:nums){
            toatalSum += n;
        }
        int i=0,j=nums.size();

        int player1Socre = solve(nums, i,j-1);

        int player2Score = toatalSum - player1Socre;

        return player1Socre>= player2Score;

    }
};