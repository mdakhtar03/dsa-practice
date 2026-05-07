class Solution {
public:
    int convertToInt(string &s){
        int HH = (stoi(s.substr(0,2)));
        int MM = (stoi(s.substr(3,2)));
        return 60*HH + MM;
    }
    int findMinDifference(vector<string>& timePoints) {
       vector<int> times;
       for(auto time:timePoints){
        times.push_back(convertToInt(time));
       }
        sort(times.begin(),times.end());
        int minTime = INT_MAX;
        for(int i=0;i<times.size()-1;i++){
            int diff=abs(times[i+1]-times[i]);
            if(diff>720){
                diff=1440-diff;
            }
            if(minTime > diff){
                minTime = diff;
            }
            int lastDiff = times[0]+1440 - times[times.size()-1];
            if(minTime>lastDiff){
                minTime = lastDiff;
            }
        }
        return minTime;
    }
};