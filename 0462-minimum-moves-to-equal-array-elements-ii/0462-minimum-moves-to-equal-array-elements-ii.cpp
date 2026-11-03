class Solution {
public:
    int minMoves2(vector<int>& nums) {
         int n = nums.size();
        sort(begin(nums), end(nums));

        int median = nums[n/2];

        unsigned int moves = 0;

        for(int i=0; i<n ; i++){
            moves += abs(nums[i]-median);
        }
        return moves;
    }
};