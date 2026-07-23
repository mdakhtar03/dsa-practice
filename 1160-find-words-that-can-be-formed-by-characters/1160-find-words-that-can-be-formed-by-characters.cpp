class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> mp(26,0);
        for(char &ch:chars){
            int alpha = ch-'a';
            mp[alpha]++;
        }
        vector<int> copymap = mp;
        int ans = 0;
        for(string &word:words){
            mp = copymap;
            for(int i=0; i<word.size(); i++){
                
                char ch = word[i];
                if(mp[ch-'a'] == 0){
                    
                    break;
                }
                else{
                    mp[ch-'a']--;
                    if(word.size()-1 == i){
                        ans += word.size();

                    }
                    
                }
            }
            
        }
        return ans;
    }
};