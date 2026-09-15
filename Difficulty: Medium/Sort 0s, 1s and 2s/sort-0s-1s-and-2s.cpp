class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        int n = arr.size()-1;
        int index = 0;
        int i =0; int j = n;
        
        while(i<=j){
            if(arr[i] == 0){
                swap(arr[i],arr[index]);
                index++;
                i++;
            }
            else if(arr[i] == 2){
                swap(arr[i],arr[j]);
                j--;
            }
            else{
                i++;
            }
        }
    }
};