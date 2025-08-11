class Solution {
  public:
    void topoSortDFS(unordered_map<int,vector<int>>&adj,vector<bool>&visited,int u,stack<int>&st){
        visited[u]=true;
        
        for(auto v:adj[u]){
            if(!visited[v]){
                topoSortDFS(adj,visited,v,st);
            }
        }
        st.push(u);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<bool>visited(V,false);
        unordered_map<int,vector<int>>adj;
        stack<int>st;
        vector<int>result;
        for(auto vec:edges){
            int u=vec[0];
            int v=vec[1];
            adj[u].push_back(v);
            
        }
        for(int i=0;i<V;i++){
            if(!visited[i]){
                topoSortDFS(adj,visited,i,st);
            }
        }
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }
        return result;
    }
};