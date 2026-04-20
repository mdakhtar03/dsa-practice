class Solution {
public:
    int maxDistance(vector<int>& colors) {
         int maxDistance=-1;
         
        for(int i=0; i<colors.size();i++){
           for(int j=0; j<colors.size();j++)
           {
            if(colors[j] != colors[i]){
                maxDistance = max(maxDistance,abs(i-j));
            }
           } 
        }
        return maxDistance;
    }
};