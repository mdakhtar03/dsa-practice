class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        vector<int> freq(1e5+1,0);
        unsigned long long ans=0;
        int totalOp = k1+k2;
        int i=0;
        while(i<nums1.size()){
            int diff = abs(nums1[i]-nums2[i]);
            freq[diff]++;
            i++;
        }

        for(int i=1e5; i>0 && totalOp>0; i--){
            int countOps  = min(freq[i],totalOp);
            freq[i] -= countOps;
            freq[i-1] += countOps;
            totalOp -= countOps;
            
        }

        for(long long i=1; i<=1e5; i++){
            ans += (freq[i]*i*i);
        }

        return ans;
        
    }
};