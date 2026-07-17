class Solution {
  public:
    bool dfsHelper(int src,
                    unordered_map<int,vector<int>> &adjList,
                    unordered_map<int,bool> &Visited,
                    unordered_map<int,bool> &dfsTracker){
        dfsTracker[src] = true;
        Visited[src] = true;
        
        for(auto nbr : adjList[src]){
            if(!Visited[nbr]){
                
            bool ans = dfsHelper(nbr,adjList, Visited, dfsTracker);
            if(ans==true) return true;
            }
            else if(Visited[nbr] == true && dfsTracker[nbr] == true){
                return true;
            }
        }
        //Backtrack
        dfsTracker[src] = false;
        return false;
    }
    bool checkCycleUsingDFS(int V, 
    unordered_map<int,vector<int>> &adjList){
        unordered_map<int,bool> Visited;
        unordered_map<int,bool> dfsTracker;
        //disconnected components
        for(int src=0; src<V;src++){
            if(!Visited[src]){
                bool ans = dfsHelper(src, adjList, Visited, dfsTracker);
                if(ans) return true;
            }
        }
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        
        //Making Adjacency List 
        unordered_map<int,vector<int>> adjList;
        for(auto edge:edges){
            int u = edge[0];
            int v = edge[1];
            //u->v
            adjList[u].push_back(v);
        }
        bool ans = checkCycleUsingDFS(V, adjList);
        return ans;
    }
};