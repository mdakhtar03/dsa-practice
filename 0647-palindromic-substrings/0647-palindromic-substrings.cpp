class Solution {
public:
    void checkPalindrome(string s,int i, int j, int &count){
        while(i>=0 && j<s.size()){
            if(s[i]==s[j]){
                count++;
            i--;
            j++;
            }
            else{
                break;
            }
        }
        
    }

    int countSubstrings(string s) {
        int count=0;
        for(int centre=0;centre<s.size();centre++){
            int i=centre;
            int j=centre;
             checkPalindrome(s,i,j,count);
            i=centre;
            j=centre+1;
            checkPalindrome(s,i,j,count);
        }
        return count;
    }
};