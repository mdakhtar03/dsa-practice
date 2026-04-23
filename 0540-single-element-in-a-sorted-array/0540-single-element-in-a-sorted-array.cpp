class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int size=nums.size();
        int s=0,e=size-1;
        while(s<=e){
            int mid=s+((e-s)>>1);

            if(s==e){
                return nums[s];
            }

            int currentValue=nums[mid];
            int leftValue;
            if(mid-1>=0){
             leftValue=nums[mid-1];
            }
            int rightValue;
            if(mid+1<size){
             rightValue=nums[mid+1];
            }

            if(currentValue != leftValue && currentValue != rightValue){
                return currentValue;
            }
            else if(currentValue == leftValue){
                int startingIndex=mid-1;
                    if(startingIndex&1){
                        e=mid-1;
                    }
                    else{
                        s=mid+1;
                    }
            }
            else if(currentValue == rightValue){
                    int startingIndex=mid;
                    if(startingIndex&1){
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