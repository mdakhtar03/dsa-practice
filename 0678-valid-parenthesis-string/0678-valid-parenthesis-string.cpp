class Solution {
public:
    // bool solve(int i, int openBrace, string s){
    //     if(i == s.size()){
    //         return openBrace == 0;
    //     }
    //     bool valid=false;
    //     if(s[i] == '('){
    //         valid |= solve(i+1, openBrace+1, s);
    //     }
    //     else if(s[i] == '*'){
    //             valid |= solve(i+1, openBrace+1,s);
    //             valid |= solve(i+1, openBrace,s);
    //             if(openBrace >0){
    //                 valid |= solve(i+1, openBrace-1,s);
    //             }
    //         }
    //     else if(openBrace > 0){
    //         valid |= solve(i+1, openBrace-1,s);
    //     }

    //     return valid;

    // }
    bool solveUsingMem(int i, int openBrace, string s, vector<vector<int>> &arr){
        if(i == s.size()){
            return openBrace == 0;
        }
        bool valid=false;

        if(arr[i][openBrace] != -1){
            return arr[i][openBrace];
        }

        if(s[i] == '('){
            valid |= solveUsingMem(i+1, openBrace+1, s,arr);
        }
        else if(s[i] == '*'){
                valid |= solveUsingMem(i+1, openBrace+1,s,arr);
                valid |= solveUsingMem(i+1, openBrace,s,arr);
                if(openBrace >0){
                    valid |= solveUsingMem(i+1, openBrace-1,s,arr);
                }
            }
        else if(openBrace > 0){
            valid |= solveUsingMem(i+1, openBrace-1,s,arr);
        }
        arr[i][openBrace] = valid;
        return arr[i][openBrace];

    }
    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<int>> arr(n+1,vector<int> (n+1, -1));
        return solveUsingMem(0,0,s,arr);
    }
};