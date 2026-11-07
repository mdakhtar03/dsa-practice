class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        //Free server

        vector<int> ans;
        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> freeServers;

        for(int i=0; i<servers.size(); i++){
            freeServers.push({servers[i],i});
        }

        //Busy Server
       priority_queue<
                    tuple<long long,int,int>,
                    vector<tuple<long long,int,int>>,
                    greater<tuple<long long,int,int>>
                > busyServers;
        long long currentTime = 0;
        int freeServerIndex;
        int freeServerWeight;
        for(int i=0;i<tasks.size();i++){
            currentTime = max(currentTime,(long long)i);

            while(!busyServers.empty() && currentTime >= get<0>(busyServers.top())){
                    int serverWeight = get<1>(busyServers.top());
                    int serverIndex = get<2>(busyServers.top());
                    busyServers.pop();
                    freeServers.push({serverWeight, serverIndex});
                }


            if(freeServers.empty()) {
                currentTime = get<0>(busyServers.top());
                while(!busyServers.empty() && currentTime >= get<0>(busyServers.top())){
                    int serverWeight = get<1>(busyServers.top());
                    int serverIndex = get<2>(busyServers.top());
                    busyServers.pop();
                    freeServers.push({serverWeight, serverIndex});
                }
            }

            

            long long completionTime = tasks[i] + currentTime;

            if(!freeServers.empty()) {
                freeServerWeight = freeServers.top().first;
                freeServerIndex  = freeServers.top().second;

            

                    freeServers.pop();

                    busyServers.push({completionTime,freeServerWeight,freeServerIndex});
            }
            
                

            ans.push_back(freeServerIndex);

        }


    return ans;
    }
};