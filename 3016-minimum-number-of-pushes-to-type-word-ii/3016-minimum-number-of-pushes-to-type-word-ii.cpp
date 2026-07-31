class Solution {
public:

    int minimumPushes(string word) {
        unordered_map<int,vector<int>> num_map; //2 3 4 5 6 7 8 9 
        vector<int> char_map(26,0);

        for(char &ch:word){
            int alpha = ch-'a';
            char_map[alpha]++;
        }
        

       sort(begin(char_map), end(char_map),
                    [](int a, int b) {
                        return a > b;
                    });
        
        int count = 0;
        int j=2, i = 0;
        while(i<char_map.size()){
            if(j==10){
                j=2;
            }

            num_map[j].push_back(char_map[i]);
            
            j++;
            i++;

        }
        for(auto it:num_map){
            for(int i=0;i<it.second.size();i++){
                count += (i+1)*it.second[i];
            }
        }
    return count;
    }
};