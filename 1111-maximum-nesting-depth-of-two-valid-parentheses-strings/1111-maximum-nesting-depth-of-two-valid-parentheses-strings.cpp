class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        
        vector<int> ans;
        int maxDepth = 0;
        for(char &ch:seq){
            char alpha = ch;
            if(alpha == '('){
               
                maxDepth++;
                if(maxDepth % 2 == 0){
                ans.push_back(1);
                }
                else{
                    ans.push_back(0);
                }
            }
            else{
            
               
                if(maxDepth % 2 == 0){
                ans.push_back(1);
                }
                else{
                    ans.push_back(0);
                }
                 maxDepth--;
            }

            
        }
        return ans;
    }
};