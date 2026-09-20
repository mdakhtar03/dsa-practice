class Solution {
public:
    int reverseDegree(string s) {
        unordered_map<char,int> mp;
        unsigned ans = 0;
        int pos = 1;
        char a='a';
        for(int i=26;i>=1;i--){
            mp[a++]=i;
        }

        for(char &ch:s){
            ans += mp[ch]*pos;
            pos++;
        }
        return ans;
    }
};