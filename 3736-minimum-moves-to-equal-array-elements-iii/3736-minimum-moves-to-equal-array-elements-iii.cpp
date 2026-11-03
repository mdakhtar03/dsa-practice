class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxElement = *max_element(nums.begin(), nums.end());
        // sort(nums.begin(), nums.end());
        int moves = 0;

        for(int i=0; i<nums.size();i++){
            if(maxElement > nums[i]){

            moves += maxElement - nums[i];
            }
        }
    return moves;

    }
};