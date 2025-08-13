class Solution {
  public:
    bool isDfsBipartite(unordered_map<int,vector<int>>&graph, vector<int>&visited,int u,int colorU){
        visited[u]=colorU;

        for(auto v:graph[u]){
            if(visited[v]==colorU){
                return false;
            }
            if(visited[v]==-1){
                //colorv opposite
                int colorV=1-colorU; // or use manual if else
                if(!isDfsBipartite(graph,visited,v,colorV)){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(int n, vector<vector<int>> &graph) {
        // Code here
        
        vector<int>visited(n,-1);
        unordered_map<int,vector<int>>adj;
        for(auto vc:graph){
            int u=vc[0];
            int v=vc[1];
            adj[u].push_back(v);
            adj[v].push_back(u); // ✅ add reverse edge
        }

        for(int i=0;i<n;i++){
            if(visited[i]==-1){
                if(!isDfsBipartite(adj,visited,i,0)){
                    return false;
                }
            }
        }
        return true;
    }
};