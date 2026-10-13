class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<int> copy;
        copy = nums;
        long long left=0, right=0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            copy[i] = abs(copy[i]);
        }
        auto compareDescending = [](int a, int b) {
        return a > b;
        };
        sort(copy.begin(),copy.end(),compareDescending);
        int i=0,j=n-1;
        while(i < j){
            left += (copy[i])*(copy[i]);
            right += (copy[j])*(copy[j]);
            i++;
            j--;
        }
        long long ans = left - right;
        if(n%2 != 0){
            ans += copy[(n)/2]*copy[n/2];
        }
        return ans;
    }
};