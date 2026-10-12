class Solution {
public:
    
     int mod = 1e9+7;
    int maxSum(vector<int>& nums, int k) {
        vector<int> totalBitCount(32,0);
        for(int &num:nums){
            for(int i=0; i<32; i++){
                if(num&(1<<i)){
                    totalBitCount[i]++;
                }
            }
        }
        long long curr=0;
        long long ans = 0;
        while(k--){
            curr = 0;
            for(int i=0;i<32;i++){
                if(totalBitCount[i]>0){
                    totalBitCount[i]--;
                    curr = (curr|1<<i); 
                }
            }
            ans = (ans +(curr*curr))%mod;
        }
        return ans;
    }
};