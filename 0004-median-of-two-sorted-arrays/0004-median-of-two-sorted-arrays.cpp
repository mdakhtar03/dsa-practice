class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> arr;
        int i=0,j=0;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]<nums2[j]){
                arr.push_back(nums1[i]);
                i++;
            }
            else{
                arr.push_back(nums2[j]);
                j++;
            }
        }
        if(i<nums1.size()){
            while(i<nums1.size()){
                arr.push_back(nums1[i]);
                i++;
            }
        }
        else{
             while(j<nums2.size()){
                arr.push_back(nums2[j]);
                j++;
            }
        }
        int arrSize = arr.size();
        double median;
        if(arrSize%2 == 1){
            int index = arrSize/2;
            median = arr[index]*1.0;
            
        }

        else{
            int index1,index2;
            index1 = arrSize/2-1;
            index2 = arrSize/2;
            median = (arr[index1]*1.0 + arr[index2]*1.0)/2;
        }
return median;

    }
};