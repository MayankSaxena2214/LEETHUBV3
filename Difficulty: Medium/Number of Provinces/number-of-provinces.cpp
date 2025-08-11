// User function Template for C++

class Solution {
  public:
    void dfs(unordered_map<int,vector<int>>&adj,vector<bool>&visited,int u){
        visited[u]=true;

        for(auto v:adj[u]){
            if(!visited[v]){
                dfs(adj,visited,v);
            }
        }
        
    }
    int numProvinces(vector<vector<int>> edges, int V) {
        // code here
        int count=0;
        int n=V;
        vector<bool>visited(n,false);
        unordered_map<int,vector<int>>adj;
        // for(auto vc:edges){
        //     int u=vc[0];
        //     int v=vc[1];
        //     adj[u].push_back(v);
        //     adj[v].push_back(u);
        // }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(edges[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(!visited[i]){
                count++;
                dfs(adj,visited,i);
            }
        }
        return count;
        
    }
};