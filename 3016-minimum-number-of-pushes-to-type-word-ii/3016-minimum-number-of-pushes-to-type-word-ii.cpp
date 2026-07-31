class Solution {
public:

    int minimumPushes(string word) {
        
        vector<int> char_map(26,0);

        for(char &ch:word){
            int alpha = ch-'a';
            char_map[alpha]++;
        }
        

       sort(begin(char_map), end(char_map),
                    [](int a, int b) {
                        return a > b;
                    });
        
        int count = 0;
        for(int i=0;i<26;i++){
            count += ((i/8)+1)*char_map[i];
        }        
    return count;
    }
};