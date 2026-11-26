class Solution {
public:
    typedef long long ll;
    int MOD = 1e9+7;
    ll power(ll base, int exp) {
        if(exp == 0)
            return 1;


        ll half = power(base, exp/2);
        ll result = (half*half)%MOD;
        if(exp %2 ==1){
            result = (result*base)%MOD;
        }
        return result;
    }

  



    bool check(vector<int>& nums, int size, int base){
        int n = nums.size();
        unordered_map<ll, int> mp;
        ll hash = 0;
        int i = 0;
        int j = 0;

        ll p = power(base,size-1);

        while(j<n){
            hash = (hash*base + nums[j])%MOD;
            if(j-i+1 < size){
                j++;
            }
            else{
                mp[hash]++;
                hash = (hash - (p*nums[i])%MOD + MOD)%MOD;
                i++;
                j++;
            }
        }

        for(auto &it:mp){
            if(it.second == 1){
                return true;
            }
        }

        return false;

    }
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int base = *max_element(begin(nums),end(nums))+1;
        int ans=1;
        int l = 1;
        int r = n;
        while(l<=r){
            int mid = l + (r-l)/2;

            if(check(nums, mid, base)){
              ans = mid;
              r= mid -1;
            }
            else{
                l = mid+1;
            }
        }

        return ans;
    }
};