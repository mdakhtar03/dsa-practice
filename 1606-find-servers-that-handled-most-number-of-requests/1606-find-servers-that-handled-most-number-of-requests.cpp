class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> readyServer;
        vector<int> ans;
        for(int i=0; i<k; i++){
            readyServer.insert(i);
        }

        priority_queue< pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>>> busyServer;

        vector<int> countReq(k,0);

        for(int i=0; i<arrival.size(); i++){
            int time = arrival[i];

            while(!busyServer.empty() && busyServer.top().first <= time){
                int server = busyServer.top().second;
                busyServer.pop();
                readyServer.insert(server);
            }

            int target = i%k;
            auto it = readyServer.lower_bound(target);

            if(it == readyServer.end()){
                it = readyServer.begin();
            }

            if(readyServer.empty()){
                continue;
            }
            int targetServer = *it;
            readyServer.erase(it);
            busyServer.push({time + load[i], targetServer});

            countReq[targetServer]++;
        }

        int maxReq = *max_element(begin(countReq), end(countReq));

        for(int i=0; i<k; i++){
            if( countReq[i]==maxReq){
                ans.push_back(i);
            }
        }
        return ans;

    }
};