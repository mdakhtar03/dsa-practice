class Solution {
public:
    bool judgeCircle(string moves) {
        int upCount=0,downCount=0,leftCount=0,rightCount=0;
        for ( auto &move:moves){
            if(move == 'U'){
                ++upCount;
            }
            if(move == 'D'){
                ++downCount;
            }
            if(move == 'L'){
                ++leftCount;
            }
            if(move == 'R'){
                ++rightCount;
            }
        }
        if(upCount == downCount && leftCount == rightCount)return 1;

        return 0;
    }
};