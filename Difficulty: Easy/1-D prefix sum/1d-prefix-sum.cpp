class Solution {
  public:
    vector<int> prefSum(vector<int> &arr) {
       vector<int> ans;
       ans.push_back(arr[0]);
       int sum = arr[0];
       for(int i=1;i<arr.size();i++){
           ans.push_back(ans.back()+arr[i]);
       }
       return ans;
    }
};