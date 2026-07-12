class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if(arr.size()==0){
            return {};
        }
        unordered_map<int,int> mp;
        vector<int> cp=arr;
        int position=1;
        sort(cp.begin(),cp.end());

        for(int i=0;i<cp.size()-1;i++){
            if((cp[i] != cp[i+1])){
                    mp[cp[i]] = position;
                    position++;
                
            }
            else{
                mp[cp[i]]=position;
            }

        }
        //last position
        int n=arr.size()-1;

        if(mp.find(cp[n]) == mp.end()){
            
            mp[cp[n]] = position;
        }
        
        for(int i=0;i<arr.size();i++){
            int num = arr[i];
            int pos = mp[num];
            arr[i]=pos;
        }
        return arr;
    }
};