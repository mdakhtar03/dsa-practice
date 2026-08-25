class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int maxMultiple=INT_MIN;
        for(auto &num:nums){
            if(num%k == 0){
                maxMultiple = max(num,maxMultiple);
               mp[num]++; 
            }
        }
        
        int ans=k;
        for(int i=k;i<=maxMultiple+k ; i += k){
                if(mp[i] == 0){
                    ans=i;
                    break;
                }
                ans=i;
        }
        return ans;
    }
};