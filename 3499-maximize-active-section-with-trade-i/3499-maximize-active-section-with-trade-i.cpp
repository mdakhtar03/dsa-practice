class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        vector<int> zeroBlocks;
        int countZeros=0;int countOnes=0;
        for(char &ch:s){
            
            if(ch == '0'){
                ++countZeros;
            }
            else{
                if (countZeros > 0)
                zeroBlocks.push_back(countZeros);
                countZeros=0;
                ++countOnes;
            }
            
        }
        if (countZeros > 0)
            zeroBlocks.push_back(countZeros);
        if(zeroBlocks.size()<2)
            return countOnes;
            
        int maxPairSum = INT_MIN;
        int i=0,j=1;int sum=0;
        
        while(j<zeroBlocks.size()){
            sum = zeroBlocks[i] + zeroBlocks[j];
            maxPairSum = max(sum,maxPairSum);
            sum=0;
            i++;
            j++;
        }
        return (maxPairSum+countOnes);
    }
};