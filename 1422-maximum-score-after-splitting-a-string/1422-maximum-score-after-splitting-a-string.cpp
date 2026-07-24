class Solution {
public:
    int maxScore(string s) {
        int ans = 0;
        for(int i=1; i<s.size();i++){
            int countZeros = 0, countOnes = 0;
            for(int j=0;j<i;j++){
                if(s[j] == '0') countZeros++;
            }
            for(int j=i;j<s.size();j++){
                if(s[j] == '1') countOnes++;
            }
            ans = max(ans, countZeros+countOnes);
        }
        return ans;
    }
};