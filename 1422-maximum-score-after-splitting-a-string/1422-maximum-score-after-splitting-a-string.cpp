class Solution {
public:
    int maxScore(string s) {
        //Score can be ZerosLeft - Ones Left + totalOnes

        int totalOnes = 0;
        for(char &ch:s){
            if(ch == '1') totalOnes++;
        }
        int score = INT_MIN;
        int leftZeros=0, leftOnes = 0;
        for(int i=0 ;i<s.size()-1;i++){
            if(s[i] == '1') 
            leftOnes++;
            else 
            leftZeros++;

            score = max(score, leftZeros-leftOnes);

        }

        return score + totalOnes;
    }
};