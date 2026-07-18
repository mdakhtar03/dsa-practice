class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s == ""){
            return 0;
        }
      deque<int> dq;
      unordered_map<int,int> mp;
      int ans = INT_MIN;
      for(int i=0; i<s.size(); i++){
            if(mp[s[i]]==0){
                dq.push_back(s[i]);
                mp[s[i]]++;
                int size = dq.size();
                ans = max(ans, size);
            }
            else {
                dq.push_back(s[i]);
                mp[s[i]]++;
                while(dq.front() != s[i]){
                    int front = dq.front();
                    mp[front]--;
                    dq.pop_front();
                }
                int front = dq.front();
                    mp[front]--;
                    dq.pop_front();
            }
      }
      return ans; 
    }
};