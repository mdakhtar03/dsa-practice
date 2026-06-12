class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        priority_queue<int, vector<int> , greater<int>> pq;
        
        for(int i=0;i<arr.size(); i++){
            pq.push(arr[i]);
        }
        int minSum=0;
        int totalSum=0;
        while(pq.size()>1){
            int element1 = pq.top();
            pq.pop();
            int element2 = pq.top();
            pq.pop();
            minSum=element1+element2;
            pq.push(minSum);
            totalSum = totalSum+minSum;
        }
        
        return totalSum;
    }
};