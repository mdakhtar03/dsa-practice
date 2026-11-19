class Solution {
public:
    int minChanges(string s) {
        int n = s.length();
        int count=0;
        int i=0;
        int j=1;
        while(i<n && j<n){
            if(s[i] != s[j]){
                count++;
            }
            i += 2;
            j += 2;
        }
        return count;
    }
};