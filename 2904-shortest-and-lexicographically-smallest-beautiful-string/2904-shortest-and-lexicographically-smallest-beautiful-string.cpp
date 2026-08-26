class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        string result = "";
        for(int len = k; len<=n;len++){
            for(int st= 0; st<=n-len; st++){
                string temp = s.substr(st,len);
                int ones=0;
                for(char &ch:temp){
                    ones += (ch=='1') ? 1 : 0;
                }
                if(ones == k){
                    if(result == "" || temp < result){
                        result = temp;
                    }
                }
            }
                if(result != ""){
                    return result;
                }
        }       
        return "";
    }
};