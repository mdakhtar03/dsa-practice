class Solution {
public:
    bool checkString(string s) {
        int countA = 0;
        for(char &ch:s){
            if(ch == 'a'){
                countA++;
            }
        }

        for(char &ch:s){
            if(ch == 'a'){
                countA--;
            }
            if(ch == 'b' && countA > 0){
                return false;
            }
            
        }

        return true;
    }
};