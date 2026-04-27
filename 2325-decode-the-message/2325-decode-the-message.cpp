class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char,char> mapping;
        char start = 'a';
        char space = ' ';
        mapping[space]=space;
        for(auto ch:key){
            if(mapping.find(ch)==mapping.end()){
                mapping[ch]=start;
                start++;
            }
        }
        string ans="";
        for(auto ch:message){
            ans.push_back(mapping[ch]);
        }
    return ans;
    }
};