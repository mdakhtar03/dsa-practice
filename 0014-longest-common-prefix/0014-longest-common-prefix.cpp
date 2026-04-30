class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int i=0;string ans;
        while(true){
            char ch=0;
            for(string &str:strs){
                if(i>=str.size()){
                    ch=0;
                    break;
                }
                if(ch==0){
                    ch=str[i];
                }
                else if(ch != str[i]){
                    ch=0;
                    break;
                }
            }
            if(ch == 0){
                break;
            }
            ans.push_back(ch);
            i++;
        }
        return ans;
    }
};