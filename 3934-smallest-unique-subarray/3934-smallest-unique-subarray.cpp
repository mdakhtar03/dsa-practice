class Solution {
public:
    using ll = long long;

     ll MOD = 1e9 + 7;

    ll power(ll base, int exp) {
        ll ans = 1;

        while(exp > 0) {
            if(exp & 1)
                ans = (ans * base) % MOD;

            base = (base * base) % MOD;
            exp /= 2;
        }

        return ans;
    }

    bool check(vector<int>& nums, int size, int base) {
        int n = nums.size();

        unordered_map<ll, int> mp;

        ll hash = 0;
        ll p = power(base, size - 1);

        // First window
        for(int i = 0; i < size; i++) {
            hash = (hash * base + nums[i]) % MOD;
        }

        mp[hash]++;

        // Remaining windows
        for(int j = size; j < n; j++) {

            // Remove outgoing element
            hash = (hash - (p * nums[j - size]) % MOD + MOD) % MOD;

            // Shift and add incoming element
            hash = (hash * base + nums[j]) % MOD;

            mp[hash]++;
        }

        for(auto& it : mp) {
            if(it.second == 1)
                return true;
        }

        return false;
    }

    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        int base = *max_element(nums.begin(), nums.end()) + 1;

        int ans = n;
        int l = 1, r = n;

        while(l <= r) {
            int mid = l + (r - l) / 2;

            if(check(nums, mid, base)) {
                ans = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }

        return ans;
    }
};