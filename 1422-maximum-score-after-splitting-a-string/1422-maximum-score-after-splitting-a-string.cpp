class Solution {
public:
    int maxScore(string s) {
        int totalOnes = 0;
        int zeros = 0; int ones=0;
        for(char &ch:s){
            if(ch == '1') totalOnes++;
        }
        int ans = 0;
        for(int i=0;i<s.size()-1;i++){
            if(s[i]=='0'){
                zeros++;
            }
            else if(s[i] == '1'){
                ones++;
            }
 
            ans = max(ans, zeros + totalOnes - ones);
        }
        return ans;
    }
};