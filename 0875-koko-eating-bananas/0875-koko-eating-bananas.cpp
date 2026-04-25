class Solution {
public:

    bool isMidValid(int k,vector<int> &piles,int h){
        long long totalHr=0;
        for (int i=0;i<piles.size();i++){
            totalHr = totalHr + ceil(piles[i]/double(k));
        }
        return totalHr<=h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int maxElement = *max_element(piles.begin(),piles.end());
        int s=1,e=maxElement;
        int ans=0;
        while(s<=e){
            int mid = (s+e)>>1;
            int k= mid;
            if(isMidValid(k,piles,h)){
                ans=mid;
                e=mid-1;
            }
            else 
            s=mid+1;
            
        }
        return ans;
    }
};