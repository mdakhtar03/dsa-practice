class Solution {
public:
    string reorganizeString(string s) {
        
        int map[256] = {0};
        for(auto ch:s){
            map[ch]++;
        }
        int maxFreq=INT_MIN;
        char maxFreqChar;

        for(int i='a' ; i<='z';i++){
            if(maxFreq<map[i]){
                maxFreq = map[i];
                maxFreqChar = i;
            }
        }
        if(maxFreq > (s.size()+1)/2){
            return "";
        }
        int index=0;
        while(maxFreq){
            s[index] = maxFreqChar;
            index=index+2;
            maxFreq--;
        }
        map[maxFreqChar] = 0;

        for(int i='a'; i<='z';i++){
            while(map[i]>0){
                index = index>=s.size()? 1: index;
                s[index] = i;
                map[i]--;
                index = index+2;
            }
        }

    return s;
    }
};