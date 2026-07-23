class Solution {
public:
    string largestGoodInteger(string num) {
       int i=0, j=1, k=2;
       int compare = -1;
       string ans;
       while(k<num.size()){
        if(num[i] == num[j] && num[j] == num[k]){
            int number = num[i] - '0';
            if(number > compare){
                ans = "";
                compare = number;
            ans += num[i];
            ans += num[j];
            ans += num[k];
            }
        }
        i++,j++,k++;

       } 
       return ans;
    }
};