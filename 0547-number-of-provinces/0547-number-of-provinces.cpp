class Solution {
public:
    void dfs(auto&adj,auto&visited,int u){
        visited[u]=true;

        for(auto v:adj[u]){
            if(!visited[v]){
                dfs(adj,visited,v);
            }
        }
        
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count=0;
        int n=isConnected.size();
        vector<bool>visited(n,false);
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
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