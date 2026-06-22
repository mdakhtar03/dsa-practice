class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> mp;

        for(char &ch:text){
            if(ch == 'b' || ch == 'l' || ch == 'a' || ch == 'o' || ch == 'n')
            mp[ch]++;
        }
        string compare = "balon";
        int ans = INT_MAX;

        for(char ch:compare){
            if(ch == 'b'){
                ans = min(ans,mp[ch]);
            }
            else if(ch == 'a'){
                ans = min(ans,mp[ch]);
            }
            else if(ch == 'n'){
                ans = min(ans,mp[ch]);
            }
            else{
                ans = min(ans,(mp[ch]/2));
            }
        }
        

    return ans;
    }
};