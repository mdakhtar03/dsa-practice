class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> temp;
        
        sort(begin(nums), end(nums));
        int target = 0;
        for(int i=0; i< n - 2 ; i++){
            int sum = nums[i];
            int k = i + 1;
            int j = n - 1;
            while(k<j){
                if((sum + nums[k] + nums[j]) == target){
                    temp.insert({sum, nums[k], nums[j]});
                    k++;
                }
                else if((sum + nums[k] + nums[j]) > target){
                    j--;
                }
                else{
                    k++;
                }
            }
        }

         vector<vector<int>> ans(temp.begin(), temp.end());
        return ans;

    }
};