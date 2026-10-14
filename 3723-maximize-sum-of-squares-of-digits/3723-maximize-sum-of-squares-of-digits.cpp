class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(num*9 < sum){
            return "";
        }
        vector<int> nums(num, 9);
        int mySum = 0;
        int i=0;
        string ans="";
        while(mySum != sum){
            if(mySum+nums[i] < sum){
                mySum += nums[i];
                ans += (to_string(nums[i]));
            }
            else{
                nums[i] = abs(sum-mySum);
                mySum += nums[i];
                ans += (to_string(nums[i]));
            }
            i++;
            
        }
        int restNumber = num - i;
        while(restNumber != 0){
            ans.push_back('0');
            restNumber--;
        }
        return ans;

    }
};