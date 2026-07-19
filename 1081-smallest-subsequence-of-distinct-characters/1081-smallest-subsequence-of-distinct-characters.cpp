class Solution {
public:
    string smallestSubsequence(string s) {
        vector<bool> marker(26,false);
        vector<int> lastIndex(26,0);

        for(int i=0; i<s.size();i++){
            int ch = s[i] - 'a';
            lastIndex[ch] = i;
        }

        string ans;
        for(int i=0;i<s.size();i++){

            if(marker[s[i]-'a']) continue;

            while(!ans.empty() 
                    && ans.back()>s[i] && 
                    lastIndex[ans.back() - 'a']>i){
                        marker[ans.back() - 'a'] = false;
                        ans.pop_back();
                    }

            marker[s[i]-'a'] = true;
            ans.push_back(s[i]);

        }
        return ans;
    }
};