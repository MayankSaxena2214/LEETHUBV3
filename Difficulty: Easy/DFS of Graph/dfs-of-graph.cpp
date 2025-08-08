class Solution {
  public:
    void dfs(vector<vector<int>>& adj,int u,vector<int>&visited,vector<int>&ans){
        if(visited[u])return;
        visited[u]=true;
        ans.push_back(u);
        //neighbours of u
        vector<int>neighbours=adj[u];
        for(auto v:neighbours){
            dfs(adj,v,visited,ans);
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int n=adj.size();
        vector<int>ans;
        vector<int>visited(n,false);
        dfs(adj,0,visited,ans);
        return ans;
    }
};