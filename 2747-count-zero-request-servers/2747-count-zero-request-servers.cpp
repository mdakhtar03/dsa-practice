class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x,
                             vector<int>& queries) {
        vector<pair<int, int>> sortedQuries;
        unordered_map<int, int> freqCount;
        vector<int> ans(queries.size(), 0);
        for (int i = 0; i < queries.size(); i++) {
            sortedQuries.push_back({queries[i], i});
        }

        sort(begin(sortedQuries), end(sortedQuries));

        sort(begin(logs), end(logs),
             [](const vector<int> a, vector<int> b) { return a[1] < b[1]; });

        queue<pair<int, int>> q;

        int startPoint = sortedQuries[0].first - x;
        int endPoint = sortedQuries[0].first;

        int totalActiveServer = 0;
        int right = 0;

        // First window
        while (right < logs.size() && logs[right][1] <= endPoint) {

            int serverId = logs[right][0];
            int time = logs[right][1];

            if (time >= startPoint) {
                q.push({serverId, time});

                freqCount[serverId]++;

                if (freqCount[serverId] == 1) {
                    totalActiveServer++;
                }
            }

            right++;
        }

        int totalInactiveServer = n - totalActiveServer;

        ans[sortedQuries[0].second] = totalInactiveServer;

        // Rest Windows..

        for (int j = 1; j < sortedQuries.size(); j++) {

            startPoint = sortedQuries[j].first - x;
            endPoint = sortedQuries[j].first;

            // Remove logs outside the left boundary
            while (!q.empty() && q.front().second < startPoint) {

                int serverId = q.front().first;
                q.pop();

                freqCount[serverId]--;

                if (freqCount[serverId] == 0) {
                    totalActiveServer--;
                }
            }

            // Add new logs up to the right boundary
            while (right < logs.size() && logs[right][1] <= endPoint) {

                int serverId = logs[right][0];
                int time = logs[right][1];

                if (time >= startPoint) {

                    q.push({serverId, time});

                    freqCount[serverId]++;

                    if (freqCount[serverId] == 1) {
                        totalActiveServer++;
                    }
                }

                right++;
            }

            // Store answer using original query index
            ans[sortedQuries[j].second] = n - totalActiveServer;
        }

        return ans;
    }
};