class Solution {
  public:
    bool checkKthBit(int n, int k) {
        //  code here
        int maskBit = 1;
        while(k){
            maskBit = maskBit<<1;
            k--;
        }
        
        return n&maskBit;
    }
};