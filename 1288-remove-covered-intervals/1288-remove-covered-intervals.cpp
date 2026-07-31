class Solution {
public:
 
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
       auto lambda=[](vector<int> &v1, vector<int> &v2){
            if(v1[0] == v2[0]){
                return v1[1]>v2[1];
            }
            else{
                return v1[0]<v2[0];
            }
        };
        sort(begin(intervals), end(intervals), lambda);
        result.push_back(intervals[0]);

        for(int i=1;i<intervals.size();i++){
            int a = intervals[i][0];
            int b = intervals[i][1];
            int c = result.back()[0];
            int d = result.back()[1];
            if(c<=a && b<=d){
                continue;
            }

                result.push_back(intervals[i]);
                
            
        }
        return result.size();
    }
};