class Solution {
  public:
    int setKthBit(int n, int k) {
        int bitMask = 1;
        while(k){
            bitMask = bitMask<<1;
            k--;
        }
        int ans = n|bitMask;
        return ans;
    }
};
