class Solution {
public:
    void solveUsingRec(int n, 
    vector<string> &ans, 
    string &store, int leftP, int rightP){
        if( n == leftP && n == rightP){
            ans.push_back(store);
            return;
        }
        //Case for Inclusion of (
        if(leftP<n){
            store.push_back('(');
            
            solveUsingRec(n,ans,store,leftP+1, rightP);
            
            store.pop_back();
        }

        //Case for Inclusion of )
        if(rightP<leftP){
            store.push_back(')');
            
            solveUsingRec(n,ans,store,leftP, rightP+1);
            store.pop_back();

        }


        


        
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string store;
        int leftP=0, rightP=0;
        solveUsingRec(n, ans, store,leftP , rightP);
        return ans;
    }
};