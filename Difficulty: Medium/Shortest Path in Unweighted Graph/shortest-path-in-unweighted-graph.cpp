class Solution {
  public:
    int shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {
        //Adjcency List
        unordered_map<int, vector<int>> adjList;
        for(auto edge:edges){
            int u = edge[0];
            int v = edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        //Parent List
        unordered_map<int,int> parent;
        //Visited true
        unordered_map<int,bool> visited;
        //Queue for bfs
        queue<int> q;
        
        //Mark for source Node
        q.push(src);
        parent[src] = -1;
        
        visited[src] = true;
        
        while(!q.empty()){
            int front = q.front();
            q.pop();
            for(auto nbr:adjList[front]){
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr] = true;
                    parent[nbr] = front;
                }
            }
        }
        
        if(!visited[dest]){
            return -1;
        }
        
        int node = dest;
        int count = 0;
        while(node != -1){
            count++;
            node = parent[node];
        }
        
        return count-1;
        
        
    }
};
