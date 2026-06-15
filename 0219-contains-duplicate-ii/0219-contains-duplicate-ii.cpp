class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int i=0;
        while(i<nums.size()){
            if(mp.find(nums[i]) == mp.end()){
                mp[nums[i]] = i;
            }
            else{
                int index = mp[nums[i]];
                if(abs(index - i)<=k){
                    return true;
                }
                else if(abs(index - i)>k){
                    mp.erase(nums[index]);
                    mp[nums[i]]=i;
                }
            }
            i++;
        }
        return false;
    }
};