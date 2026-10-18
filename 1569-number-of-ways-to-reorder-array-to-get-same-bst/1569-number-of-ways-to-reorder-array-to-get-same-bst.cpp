class Solution {
public:

    typedef long long ll;

    ll mod = 1e9 + 7;
    vector<vector<ll>> PT;
    int solve(vector<int> &nums){
        int n = nums.size();
        if(n < 3){
            return 1;
        }

        int root = nums[0];

        vector<int> left_nums;
        vector<int> right_nums;

        for(int i=1 ; i<n ; i++){
            if(nums[i]<root){
                left_nums.push_back(nums[i]);
            }
            else{
                right_nums.push_back(nums[i]);
            }
        }

        ll x = solve(left_nums);

        ll y = solve(right_nums);

        ll z = PT[n-1][left_nums.size()];
        
        return (((x * y) % mod) * z) % mod;;

    }

    int numOfWays(vector<int>& nums) {

        //Creating Pascal Triangle

        int n = nums.size();
        vector<ll> Ones;
        for(int i=0 ;i < n+1 ; i++){
            for(int j =0; j<i+1;j++){
               Ones.push_back(1); 
            }
            PT.push_back(Ones);
            Ones.clear();
        }

        for(int i=2 ; i<n+1;i++){
            for(int j=1 ; j<i ; j++){
                PT[i][j] = (PT[i-1][j-1] + PT[i-1][j])%mod;
            }
        }

        ll ans =  solve(nums);

        ans = ans -1 ;
        return ans%mod;
    }
};