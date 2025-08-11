class Solution {
  public:
    bool isCycleDFS(unordered_map<int,vector<int>>&adj,int u,vector<bool>&visited,int parent){
        visited[u]=true;
        
        for(auto v:adj[u]){
            if(v==parent)continue;
            if(visited[v]){
                return true;
            }
            if(isCycleDFS(adj,v,visited,u)){
                return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<bool>visited(V,false);
        unordered_map<int,vector<int>>adj;
        for(auto vec:edges){
            int u=vec[0];
            int v=vec[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i=0;i<V;i++){
            if(!visited[i] && isCycleDFS(adj,i,visited,-1)){
                return true;
            }
        }
        return false;
        
    }
};