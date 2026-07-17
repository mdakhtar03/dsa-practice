class Solution {
public:

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //Adjcency List
        //Indegree
        unordered_map<int,vector<int>> adjList;
        unordered_map<int,int> mp;
        int count = 0;
        for(auto edge:prerequisites){
            int u=edge[0];
            int v=edge[1];
            adjList[u].push_back(v);
            mp[v]++;
        }
        queue<int> q;
        for(int i=0; i<numCourses;i++){
            if(mp[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int front = q.front();
            q.pop();
            ++count;
            for(auto nbr:adjList[front]){
                mp[nbr]--;
                if(mp[nbr] == 0){
                    q.push(nbr);
                }
            }
        }
       return numCourses == count;
    }
};