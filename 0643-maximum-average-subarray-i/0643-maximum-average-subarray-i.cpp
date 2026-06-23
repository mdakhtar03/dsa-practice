class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double maxAvg = INT_MIN;
        double sum=0;
        deque<int> dq;
        for(int i=0; i<k; i++){
            double element = nums[i];
            sum += element;
            dq.push_back(element);
        }

        maxAvg = max(maxAvg,sum/k);

        for( int i=k; i<nums.size() && (dq.size()== k); i++){
            int front = dq.front();
            sum -= front;
            dq.pop_front();
            sum += nums[i];
            dq.push_back(nums[i]);
            maxAvg = max(maxAvg,sum/k);
        }
        return maxAvg;
    }
};