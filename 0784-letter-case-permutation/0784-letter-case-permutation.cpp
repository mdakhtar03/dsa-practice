class Solution {
public:
    void solveUsingRec(string s, vector<string> &ans, int index,
    string store){
        //Base Case
        if(index == s.size()){
            ans.push_back(store);
            return;
        }
        //Include
        char ch = s[index];
        if(s[index]>='a' && s[index]<='z'){
            ch = s[index] - 'a' + 'A';
        }
        else if(s[index]>='A' && s[index]<='Z'){
            ch = s[index] - 'A' + 'a';
        }
        store.push_back(ch);
       
        solveUsingRec(s,ans,index+1,store);

        //exlcude
        store.pop_back();
        store.push_back(s[index]);
        if(isalpha(s[index]))
        solveUsingRec(s,ans,index+1,store);
        
    }
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        string store;
        solveUsingRec(s,ans,0,store);
        return ans;
    }
};