class Solution {
  public:
    int maxProduct(vector<int>& arr) {
        // code here
           priority_queue <int> pq;
        for(auto &num:arr){
            pq.push(num);
        }
        int a=pq.top();
        pq.pop();
        int b=pq.top();

        return (a)*(b);

    }
};