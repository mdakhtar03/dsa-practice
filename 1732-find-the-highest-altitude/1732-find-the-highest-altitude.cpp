class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        for(int i=1;i<gain.size();i++){
            int modifierNum = gain[i-1];
            gain[i] = gain[i] + modifierNum;

        }
        int ans =0;
        for(int &num:gain){
            ans = max(ans,num);
        }
        if(ans>0){
            return ans;
        }
        return 0;
    }
};