class Solution {
public:
    bool isIsomorphic(string s, string t) {
        char charS='a';
        char charT='a';
        unordered_map<char,char> mapS;
        unordered_map<char,char> mapT;
        string ans1,ans2;
        for(int i=0;i<s.size();i++){
            if(mapS.find(s[i])==mapS.end()){
                mapS[s[i]]=charS;
                charS++;
            }
            if(mapT.find(t[i])==mapT.end()){
                
                mapT[t[i]]=charT;
                charT++;
                
            }
            ans1.push_back(mapS[s[i]]);
            ans2.push_back(mapT[t[i]]);
        }
         return ans1==ans2;
    }
};