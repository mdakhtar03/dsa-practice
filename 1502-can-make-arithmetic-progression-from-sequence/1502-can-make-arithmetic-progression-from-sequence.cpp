class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int j=0;
        int d=arr[0]-arr[1];
        for(int i=1;i<arr.size();i++){
            if(arr[j]-arr[i] != d){
                return false;
            }
            j++;
        }
        return true;
    }
};