class Solution {
public:
    int generateKey(int num1, int num2, int num3) {
        int lastD1=0,lastD2=0,lastD3=0;
        int number=0;int count=0;
        while(num1 && num2 && num3){
            if(num1 || num2 || num3){
                    count++;
                }
                lastD1 = num1%10;
                lastD2 = num2%10;
                lastD3 = num3%10;
                number = number*10 + min(lastD1,min(lastD2,lastD3));
                num1 /= 10;
                num2 /= 10;
                num3 /= 10;
                
        }
       //Reverse num
       int ans=0;
       int r=0;
        while(number || count){
            r=number%10;
            ans = ans*10 + r;
            number = number/10;
            count--;
        }
        

        return ans;
    }
};