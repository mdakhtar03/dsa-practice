class Solution {
public:
    int minimumPushes(string word) {
        vector<int> mp(8,0);
        int j=0;int count=0;
        for(int i=0;i<word.size();i++){

            if(j==8){
                j=0;
            }
            
                mp[j]++;
                count += mp[j];
                j++;
            
             
             
        }
    
        
        return count;
    }
};