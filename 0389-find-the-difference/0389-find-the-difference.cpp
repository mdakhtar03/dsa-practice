class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> map(26,0);
        for(char &ch:s){
            int alpha = ch - 'a';
            map[alpha]++;
        }
        char ans ;
        for(char &ch:t){
            int alpha = ch -'a';
            if(map[alpha] != 0){
               map[alpha]--; 
            }
            else if(map[alpha] == 0){
                ans = ch;
            }
        }
        return ans;
    }
};