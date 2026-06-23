class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        // write code here
        vector<int> ans;
        deque<int> dq;
        for(int i=0;i<k;i++){
            if(arr[i]<0){
                dq.push_back(i);
            }
        }
        if(dq.empty()){
            ans.push_back(0);
        }
        else{
            ans.push_back(arr[dq.front()]);
        }
        //Process remaining windows
        for(int i=k;i<arr.size();i++){
            
            
            if(!dq.empty()  && i-dq.front() >= k){
                dq.pop_front();
            }
            int element = arr[i];
            if(element <0 ){
                dq.push_back(i);
            }
            if(dq.empty()){
            ans.push_back(0);
            }
            else{
                ans.push_back(arr[dq.front()]);
            }
            
        }
        return ans;
    }
};