class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int leftCount=0,rightCount=0, dashed=0;
        for(auto &ch:moves){
            if(ch == 'L'){
                leftCount++;
            }
            else if(ch == 'R'){
                rightCount++;
            }
            else{
                dashed++;
            }
        }
        if(leftCount==0 && rightCount==0){
            return dashed;
        }
        else if(leftCount>rightCount){
            return leftCount+dashed-rightCount;
        }
        else{
            return rightCount+dashed-leftCount;
        }
    return -1;
    }
};