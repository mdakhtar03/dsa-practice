class Solution {
  public:
    int shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {
        //AdjcencyList
        unordered_map<int,vector<int>> adjList;
        for(auto edge:edges){
            int u = edge[0];
            int v = edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        //Path List
        unordered_map<int,int> path;
        queue<int> q;
        unordered_map<int,bool> visited;
        
        q.push(src);
        path[src] = -1;
        visited[src] = true;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            for(auto nbr:adjList[front]){
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr] = true;
                    path[nbr] = front;
                }
            }
        }
        if (!visited[dest])
            return -1;
        int count = 0;
        int node = dest;
        while(node != -1){
            count++;
            node = path[node];
        }
        
        
        return count-1;
    }
};
