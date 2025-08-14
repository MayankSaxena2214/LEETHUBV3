class Solution {
  public:
   vector<int>parent;
        vector<int>rank;
    void unionSets(int x,int y){
        
        int x_parent=find(x);
        int y_parent=find(y);
        
        if(x_parent==y_parent){
            return;
        }
        else if(rank[x_parent]<rank[y_parent]){
            parent[x_parent]=y_parent;
            
        }
        else if(rank[x_parent]>rank[y_parent]){
            parent[y_parent]=x_parent;
            
        }
        else{
            //equal case
            parent[x_parent]=y_parent;
            rank[x_parent]++;
        }
    }
    int find(int u){
        
        if(parent[u]==u){
            return u;
        }
        parent[u]=find(parent[u]);
        return parent[u];
    }
    // Function to detect cycle using DSU in an undirected graph.
    int detectCycle(int V, vector<int> adj[]) {
        // Code here
       
        parent.resize(V);
        rank.resize(V);
       
        
        for(int i=0;i<V;i++){
            parent[i]=i;
            rank[i]=0;
        }
        
        for(int u=0;u<V;u++){
            for(auto v:adj[u]){
                if(u<v){
                    int parent_u=find(u);
                    int parent_v=find(v);
                    
                    if(parent_u==parent_v){
                        return true;
                    }
                    unionSets(u,v);
                }
            }
        }
        return false;
        
        
        
    }
};