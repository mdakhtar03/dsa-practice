class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        string temp;
        string ans;
        int i=0, n=s.size();
        unordered_map<string,string> mp;
        for(auto arr:knowledge){
            string key = arr[0];
            string val = arr[1];
            mp[key] = val;
        }


        while(i<n){
            if(isalpha(s[i])){
               ans.push_back(s[i]);
               i++;
               continue;
            }
            else{
                // {
                i++;
                while(s[i] != ')' && i<n){
                    temp.push_back(s[i]);
                    i++;
                }
                if(mp.count(temp)>0){
                    ans += mp[temp];
                }
                else{
                    ans +=  "?";
                }
                temp = "";
            }

            i++;
        }
        return ans;
    }
};