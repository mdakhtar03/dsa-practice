class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        int maxElement = *max_element(begin(nums),end(nums));

        int BNum = 1;
        while(BNum <= maxElement){
            BNum<<=1;
        }
        vector<bool> v1(BNum,false);
        vector<bool> v2(BNum,false);

        for(int i=0; i<n;i++){
            for(int j=i;j<n;j++){
                v1[nums[i]^nums[j]] = true;
            }
        }

        for(int i=0; i<BNum; i++){
            if(v1[i] == true){
                for(int &num:nums){
                    v2[i^num] = true;
                }
            }
        }
        int count=0;
        for(int i=0;i<BNum;i++){
            if(v2[i]==true){
                count++;
            }
        }
        return count;
    }
};