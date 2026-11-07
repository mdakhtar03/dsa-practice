class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.length();

        int mid = n/2;

        if(n == 1) return "";
        bool flag = true;

        
        for(int i=0; i<mid ; i++){
           if(palindrome[i] != 'a'){
                palindrome[i] = 'a';
                flag = false;
                break;
           }
            
        }

        if(flag){
            palindrome[n-1] = 'b';
        }
        return palindrome;
    }
};