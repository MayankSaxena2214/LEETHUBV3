class Solution {
  public:
    bool isCyclicDFS(unordered_map<int,vector<int>>&adj,int u,vector<bool>&visited,vector<bool>&inRecursion){
        visited[u]=true;
        inRecursion[u]=true;
        
        for(auto v:adj[u]){
            if(!visited[v]){
                if(isCyclicDFS(adj,v,visited,inRecursion)){
                    return true;
                }
            }
            if(visited[v] && inRecursion[v]==true){
                return true;
            }
            
        }
        
        
        inRecursion[u]=false;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
         unordered_map<int,vector<int>>adj;
        vector<int>indegree(V,0);
        vector<int>result;
        queue<int>q;
        for(auto vec:edges){
            int u=vec[0];
            int v=vec[1];
            adj[u].push_back(v);
            
        }
        for(int i=0;i<V;i++){
            for(auto v:adj[i]){
                indegree[v]++;
            }
        }
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
                result.push_back(i);
            }
        }
        while(!q.empty()){
            auto u=q.front();
            q.pop();
            
            for(auto v:adj[u]){
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                    result.push_back(v);
                }
            }
        }
        if(result.size()==V)return false;
        return true;
        
        // vector<bool>visited(V,false);
        // unordered_map<int,vector<int>>adj;
        // vector<bool>inRecursion(V,false);
        // for(auto vec:edges){
        //     int u=vec[0];
        //     int v=vec[1];
        //     adj[u].push_back(v);
            
        // }
        // for(int i=0;i<V;i++){
        //     if(!visited[i] && isCyclicDFS(adj,i,visited,inRecursion)){
        //         return true;
        //     }
        // }
        // return false;
    }
};