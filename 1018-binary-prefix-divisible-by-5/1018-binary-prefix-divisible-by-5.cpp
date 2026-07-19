class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
       int pos=0;vector<bool> ans;
       int number = nums[0];

       if(number == 0) 
       ans.push_back(true);

       else 
       ans.push_back(false);

       for(int i=1; i<nums.size();i++){

            number = (number*2 + nums[i])%5;
            if(number%5 == 0){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
            
            
       }
       return ans;
    }
};