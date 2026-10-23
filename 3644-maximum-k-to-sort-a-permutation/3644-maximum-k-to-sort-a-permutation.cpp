class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int K = -1;

        for(int i=0 ;i <nums.size(); i++){
            if( i != nums[i]){
                K = K & nums[i];
            }
        }

        return K == -1 ?  0 : K;
    }
};