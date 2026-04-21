class Solution {
public:
    int minTimeToType(string word) {
        int pointer = 'a';
        int time;
        int totalTime=0;
        int i=0;
        while(i<word.length()){
            if(abs(pointer - int(word[i])) <= 13){
                time = abs(pointer - int(word[i]));
                pointer= int(word[i]);
            }
            else{
                time= 26 - abs(pointer - int(word[i]));
                pointer = int(word[i]);
            }
            totalTime=totalTime+time+1;
            i++;
        }
        return totalTime;
    }
};