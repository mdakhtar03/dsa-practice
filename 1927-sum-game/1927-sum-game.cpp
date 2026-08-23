class Solution {
public:
    bool sumGame(string num) {
        int leftSum = 0;
        int rightSum=0;

        int leftQM = 0;
        int rightQM = 0;

        for(int i=0;i<num.size();i++){
            if(num[i]=='?'){
                if(i<num.size()/2){
                    leftQM++;
                }
                else{
                    rightQM++;
                }
            }
            else{
                if(i<num.size()/2){
                    leftSum += num[i]-'0';
                }
                else{
                    rightSum += num[i]-'0';
                }
            }
        }
        if((leftQM+rightQM)%2==1){
            return true;
        }

        int TLsum = 2*leftSum + 9*leftQM;
        int TRsum = 2*rightSum + 9*rightQM;

        if(TLsum == TRsum){
            return false;
        }

        return true;

    }
};