class Solution {
public:
    int firstOccurance(vector<int>& nums, int target){
        int s=0,e=nums.size()-1;int ans=-1;
        int mid = s+ (e-s)/2;
        while(s<=e){
            if(nums[mid]==target){
                ans=mid;
                e=mid-1;
            }
            else if(nums[mid]>target){
                e=mid-1;
            }
            else {
                s = mid+1;
            }
            mid = s+ (e-s)/2;
        }
        return ans;
    }
    int lastOccurance(vector<int>& nums, int target){
        int s=0,e=nums.size()-1;int ans=-1;
        int mid = s+ (e-s)/2;
        while(s<=e){
            if(nums[mid]==target){
                ans=mid;
                s=mid+1;
            }
            else if(nums[mid]>target){
                e=mid-1;
            }
            else {
                s = mid+1;
            }
            mid = s+ (e-s)/2;
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int firtIndex = firstOccurance(nums,target);
        int lastIndex = lastOccurance(nums,target);
        return {firtIndex, lastIndex};
    }
};