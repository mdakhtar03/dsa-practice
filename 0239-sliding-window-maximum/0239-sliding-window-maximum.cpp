class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        for(int i=0; i<k; i++){

            while(!dq.empty() && nums[dq.back()]<nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }

        //ans
        int index = dq.front();
        ans.push_back(nums[index]);

        for(int i=k;i<nums.size();i++){
            //Check that the element is the part of window or not
            if(!dq.empty() && i-dq.front()>=k){
                dq.pop_front();
            }

            while(!dq.empty() && nums[dq.back()]<nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);

            index = dq.front();
            ans.push_back(nums[index]);

        }
        return ans;
    }
};