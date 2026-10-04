class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();

        int openBrace = 0;
        int closeBrace = 0;

        int maxValid = 0;
        int result = 0;
        //Left -> right Traversal

        int i = 0;
        while(i<n){
            if(s[i] == '('){
                openBrace++;
            }
            else if(s[i] == ')'){
                closeBrace++;
            }
            
            if(openBrace < closeBrace){
                  openBrace = 0;
                  closeBrace = 0;  
            }
            else if(openBrace == closeBrace){
                result = openBrace + closeBrace;
                maxValid = max(result,maxValid);
            }
            i++;
        }
        i=n-1;
        openBrace = 0;
        closeBrace = 0; 
        while(i>=0){
            if(s[i] == '('){
                openBrace++;
            }
            else if(s[i] == ')'){
                closeBrace++;
            }
            if(openBrace > closeBrace){
                  openBrace = 0;
                  closeBrace = 0;  
            }
            else if(openBrace == closeBrace){
                result = openBrace + closeBrace;
                maxValid = max(result,maxValid);
            }
            i--;
        }

        return maxValid;

    }
};