class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        set<string> city;

        for(auto &path:paths){
            string City = path[0];
            city.insert(City);
        }
        string ans;
        for(auto &path:paths){
            string City = path[1];
             if (city.find(City) == city.end()) {
                    ans = City;
                }
        }
        return ans;
    }
};