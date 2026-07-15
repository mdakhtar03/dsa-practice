class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumOfEvenNumber = n*(n+1);
        int sumOfOddNumber = n*n;
        int remainder=1;
        while(sumOfEvenNumber){
            
             remainder = sumOfEvenNumber%sumOfOddNumber;
            if(remainder == 0){
                return sumOfOddNumber;
            }
            sumOfEvenNumber=sumOfOddNumber;
            sumOfOddNumber = remainder;
        }
        return 1;
    }
};