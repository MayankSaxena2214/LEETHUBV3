// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<int>result(V,INT_MAX);
        
        
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        unordered_map<int,vector<pair<int,int>>>adj;
        
        for(auto &vec:edges){
            int u=vec[0];
            int v=vec[1];
            int wt=vec[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        
        result[src]=0;
        
        pq.push({0,src});
        
        while(!pq.empty()){
             auto pqtop=pq.top();
             pq.pop();
             
             int dist=pqtop.first;
             int u=pqtop.second;
             
             for(auto &pr:adj[u]){
                 int d=pr.second;
                 int v=pr.first;
                 
                 if(dist+d<result[v]){
                     //can update here
                     result[v]=dist+d;
                     pq.push({d+dist,v});
                 }
             }
        }
        return result;
        
    }
};