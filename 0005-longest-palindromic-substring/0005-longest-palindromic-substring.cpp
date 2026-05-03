class Solution {
public:
    string givePalindrome(string s,int i,int j){
        string subStr="";
        while(i>=0 && j<s.size()){
            if(s[i]!=s[j]){
                break;
            }
            i--;
            j++;
        }
        i=i+1;
        j=j-1;
        while(i<=j){
            subStr.push_back(s[i]);
            i++;
        }
        return subStr;
    }
    string longestPalindrome(string s) {
        string ans="";
      
          for(int centre =0 ;centre<s.size();centre++){
            int i=centre;
            int j=centre;

             string subStr1 = givePalindrome(s,i,j);

             i=centre;
             j=centre+1;

             string subStr2 = givePalindrome(s,i,j);

            if(ans.size()<subStr1.size()){
                ans="";
                ans = subStr1;
            }
            if(ans.size()<subStr2.size()){
                ans="";
                ans=subStr2;
            }
          }
        
        return ans;
    }
};