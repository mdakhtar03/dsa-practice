class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        ans.push_back({intervals[0][0],intervals[0][1]});
        // return intervals;

        for(int i=0; i<intervals.size();i++){
            if(ans.back()[1]>=intervals[i][0]){
                    ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }else{
                ans.push_back({intervals[i][0],intervals[i][1]});
            }
        }

       return ans;

    }
};