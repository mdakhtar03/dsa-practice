class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int minimize=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(target == nums[i]){
                if(minimize> abs(i-start))
                {
                    minimize=abs(i-start);
                }
            }
        }
        return minimize;
    }
};