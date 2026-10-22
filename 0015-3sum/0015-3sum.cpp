class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> temp;
        vector<vector<int>> ans;
        sort(begin(nums), end(nums));
        int target = 0;
        for(int i=0; i< n - 2 ; i++){
            int sum = nums[i];

            if(i>0 && nums[i] == nums[i-1]) continue;

            int k = i + 1;
            int j = n - 1;
            while(k<j){
                if((sum + nums[k] + nums[j]) == target){
                    ans.push_back({sum, nums[k], nums[j]});
                    k++; j--;
                    while(k<j && nums[k] == nums[k-1]) k++;

                    while(k<j && nums[j] == nums[j+1]) j--;

                }
                else if((sum + nums[k] + nums[j]) > target){
                    j--;
                }
                else{
                    k++;
                }
            }
        }

        
        return ans;

    }
};