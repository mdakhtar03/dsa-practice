class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp;

        for(int &num:nums){
            if(mp[num] == 1)
                return num;
            
            mp[num]++;
        }

        return -1;
    }
};