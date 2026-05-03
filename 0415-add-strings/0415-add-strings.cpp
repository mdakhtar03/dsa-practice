class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans;
        int i=num1.size()-1;
        int j=num2.size()-1;
        int carry = 0;
        while(i>=0 || j>=0 || carry !=0){
            int sum=0;

            if(i>=0){
                int lastDigit = num1[i]-'0';
                sum = sum + lastDigit;
                i--;
            }  
            if(j>=0){
                int lastDigit = num2[j]-'0';
                sum = sum + lastDigit;
                j--;
            }
            sum = sum + carry;
            int lastDigit = sum%10;
            ans.push_back(lastDigit + '0');
            carry = sum/10;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};