class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<bool> marker(26,false);
        vector<int> lastOccurance(26,0);
        for(int i=0; i<s.size();i++){
            int ch = s[i] - 'a';
            lastOccurance[ch] = i;
        }
        string ans;
        for(int i=0;i<s.size(); i++){
            int ch = s[i] - 'a';
            
            if(marker[ch]) continue;

            while(!ans.empty() && ans.back()>s[i] 
                    && lastOccurance[ans.back()-'a']>i){
                        marker[ans.back()-'a']=false;
                        ans.pop_back();
                    }
            ans.push_back(s[i]);
            marker[s[i]-'a'] = true;
        }
        return ans;
    }
};