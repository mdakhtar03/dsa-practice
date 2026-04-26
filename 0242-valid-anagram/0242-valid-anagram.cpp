class Solution {
public:
    bool isAnagram(string s, string t) {
       vector<int> alphas(26,0);
       if(s.size()!=t.size()){
        return false;
       }
       for(int i=0;i<s.size();i++){
            alphas[s[i]-'a']++;
            alphas[t[i]-'a']--;
       }
       for(int i=0;i<alphas.size();i++){
            if(alphas[i] != 0){
                return false;
            }
       }
       return true;
    }
};