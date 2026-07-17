class Solution {
  public:
    vector<int> solve(int V,
    unordered_map<int,vector<int>> &adjList,
    unordered_map<int,int> inDegree){
        queue<int> q;
        vector<int> ans;
        for(int i=0; i<V;i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }
        
        //Main Logic
        while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            ans.push_back(frontNode);
            for(auto nbr: adjList[frontNode]){
                inDegree[nbr]--;
                if(inDegree[nbr]==0){
                    q.push(nbr);
                }
            }
            
        }
        
        return ans;
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        //Adjcency List
        unordered_map<int,vector<int>> adjList;
        
        for(auto edge:edges){
            int u = edge[0];
            int v = edge[1];
            adjList[u].push_back(v);
        }
        //All inDegree
        unordered_map<int,int> inDegree;
        for(auto edge:edges){
            int u = edge[0];
            int v = edge[1];
            //U->V
            inDegree[v]++;
        }
        
        vector<int> ans;
        ans = solve(V,adjList,inDegree);
        return ans;
        
    }
};