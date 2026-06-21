class Solution {
  public:
    bool isFactorial(int num, int divisor){
        //Base case
        if(num == 1){
            return true;
        }
          if(num % divisor != 0) {
        return false;
    }
        num = num/divisor;
        bool ans = isFactorial(num, divisor+1);
        return ans;
    }
    vector<int> factorialNumbers(vector<int>& arr) {
        vector<int> ans;
        int i=2;
        for(int &num:arr){
            if(isFactorial(num,i)){
                ans.push_back(num);
            }
        }
        return ans;
        
    }
};