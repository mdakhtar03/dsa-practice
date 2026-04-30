class Solution {
public:
    string reverseOnlyLetters(string s) {
        string ans=s;
        int i=0,j=s.size()-1;
        while(i<j){
              if(!((ans[i] >= 'A' && ans[i] <= 'Z') || (ans[i] >= 'a' && ans[i] <= 'z'))){
                i++;
            }
            else if(!((ans[j] >= 'A' && ans[j] <= 'Z') || (ans[j] >= 'a' && ans[j] <= 'z'))){
                j--;
            }
            else {
            swap(ans[i],ans[j]);
                i++;
                j--;
            }
 
        }
        return ans;
    }
};