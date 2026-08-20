class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1;
        vector<int> arr2;
        vector<int> ans;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        for(int i=2; i<nums.size(); i++){
            int num = nums[i];
            if(arr2.back()<arr1.back()){
                arr1.push_back(num);
            }
            else{
                arr2.push_back(num);
            }

        }

        for(int &n:arr1){
            ans.push_back(n);
        }
        for(int &m:arr2){
            ans.push_back(m);
        }
        

        return ans;
    }
};