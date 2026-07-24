class Solution {
public:
    bool isPathCrossing(string path) {
        set<string> ranges;
        int x=0, y=0;
        ranges.insert(to_string(x)+ "," + to_string(y));
        for(char &ch:path){
            if(ch == 'N'){
                y++;
            }
            else if(ch == 'S'){
                y--;
            }
            else if(ch == 'E'){
                x++;
            }
            else if(ch == 'W'){
                x--;
            }

            if(ranges.find(to_string(x)+ "," + to_string(y))!=ranges.end()){
                return true;
            }
            else{
                ranges.insert(to_string(x)+ "," + to_string(y));
            }
        }
        
        return false;
    }
};