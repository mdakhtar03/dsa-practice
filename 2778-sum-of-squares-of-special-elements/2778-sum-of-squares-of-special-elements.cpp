class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        unsigned int ans = 0;
        int k=1;
        int n = nums.size();
        for(int i=0; i<nums.size(); i++){
            if(n%k == 0){
                ans += (nums[i]*nums[i]);
            }
            k++;
        }
        return ans;
    }
};