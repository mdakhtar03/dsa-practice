class Solution {
public:
    int numberOfMatches(int n) {
        int numberOfmatches = 0;
        int matches=0;
        int team = n;
        int totalMatches = 0;
        while(team != 1){
            matches = team/2;
            team = team - matches;
            totalMatches += matches;
        }
        return totalMatches;
    }
};