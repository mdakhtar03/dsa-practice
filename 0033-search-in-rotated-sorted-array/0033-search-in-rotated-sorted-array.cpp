class Solution {
public:
      int findPivotIndex(vector<int>& nums){
        int s=0,e=nums.size()-1;
        int lastElement=nums[e];
        int ans=-1;
        while(s<=e){
            int mid = s+(e-s)/2;
            if(nums[mid]<=lastElement){
                e=mid-1;
            }
            else{
                ans=mid;
                s=mid+1;
            }
        }
        return ans;
}

    int search(vector<int>& nums, int target) {
        int n=nums.size()-1;
        int lastIndex=nums[n];
        int pivotIndex=findPivotIndex(nums);
        if(target <=lastIndex){
            int s= pivotIndex+1,e=nums.size()-1;
            while(s<=e){
                int mid=s+(e-s)/2;
                if(nums[mid]==target){
                    return mid;
                }
                else if(nums[mid]>target){
                    e=mid-1;
                }
                else{
                    s=mid+1;
                }
            }
        }
        else {
            int s=0,e=pivotIndex;
            while(s<=e){
                int mid=s+(e-s)/2;
                if(nums[mid]==target){
                    return mid;
                }
                else if(nums[mid]>target){
                    e=mid-1;
                }
                else{
                    s=mid+1;
                }
            }
        }
        return -1;
    }
};