class Solution {
  public:
    int setBits(int n) {
        // Write Your Code here
        int count = 0;
        while(n != 0){
            count++;
            n = n & (n-1);
        }
        return count;
    }
};