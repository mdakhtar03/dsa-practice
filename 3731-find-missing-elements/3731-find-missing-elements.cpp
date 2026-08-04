class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mn = *min_element(nums.begin(), nums.end());
    int mx = *max_element(nums.begin(), nums.end());

    unordered_map<int,int> mp;
    for(int &num:nums){
        mp[num]++;
    }
    vector<int> ans;

    for(int i = mn; i <= mx; i++){
        if(mp[i]==0)
            ans.push_back(i);
    }

    return ans;
    }
};