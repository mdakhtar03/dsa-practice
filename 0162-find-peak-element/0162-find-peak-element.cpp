class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int s=0,e=nums.size()-1;
        int mid;
        while(s<=e){
             mid = s+((e-s)>>1);
            
           if( mid+1<nums.size() &&nums[mid]<nums[mid+1]){
            s=mid+1;
           }
           else{
            e=mid-1;
           }
            
           
        }
        return s;
    }
};