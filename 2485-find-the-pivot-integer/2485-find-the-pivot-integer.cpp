class Solution {
public:
    int pivotInteger(int n) {
        int copy=0;
        int mid=n/2;
        int leftSum=0, rightSum=0;
        while(copy<=n){
             for(int i=1; i<=copy; i++){
                leftSum=leftSum+i;
            }
            for(int j=copy;j<=n; j++){
                rightSum=rightSum+j;
            }
            if(leftSum == rightSum){
                return copy;
            }
            else{
                leftSum=0;
                rightSum=0;
            }
            copy++;
        }
        return -1;
    }
};