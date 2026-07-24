class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string,int> mp;

        for(auto &path:paths){
            string City = path[0];
            mp[City]++;
        }
        string ans;
        for(auto &path:paths){
            string City = path[1];
             if (mp[City] == 0) {
                    ans = City;
                }
        }
        return ans;
    }
};