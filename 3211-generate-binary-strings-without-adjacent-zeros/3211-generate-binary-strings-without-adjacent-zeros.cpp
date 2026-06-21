class Solution {
public:
    void solveUsingRec(int n, vector<string> &ans, string store){
        //Base Case
        if(n == 0){
            ans.push_back(store);
            return;
        }
        store.push_back('1');
        solveUsingRec(n-1,ans,store);
        store.pop_back();
        if(store.empty() || store.back() != '0'){
            store.push_back('0');
            solveUsingRec(n-1,ans,store);
            store.pop_back();
        }
    }
    vector<string> validStrings(int n) {
        vector<string> ans;
        string store;
        solveUsingRec(n,ans, store);
        return ans;
    }
};