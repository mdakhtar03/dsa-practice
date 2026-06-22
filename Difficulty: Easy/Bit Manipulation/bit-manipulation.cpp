class Solution {
  public:
    void bitManipulation(int num, int i) {
        // your code here
        int bitMask = 1;
        int index = i;
        
        // Get Bit
        while(index != 1){
            bitMask = bitMask<<1;
            index--;
        }
        
        int getBit =   num&bitMask;
        if(num&bitMask){
            cout<<1<<" ";
        }
        else
        cout<<0<<" ";
        
        //Set Bit
        index = i;
        bitMask = 1;
        while(index != 1){
            bitMask = bitMask<<1;
            index--;
        }
        
        int setBit = bitMask|num;
        cout<<setBit<<" ";
        
        
        index = i;
        bitMask = 1;
        
        index = i;
        bitMask = 1;
        while(index != 1){
            bitMask = bitMask<<1;
            index--;
        }
        
        
        
        int clearBit = (~bitMask)&num;
        
        cout<< clearBit<<" ";
        
        
    }
};