class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int i=0, j= arr.size()-1;

        while(j-i>=k){
            if(x-arr[i]<=arr[j]-x){
               j--;
            }
            else{
                i++;
            }
        }
        return vector<int> (arr.begin()+i,arr.begin()+j+1);
    }
};