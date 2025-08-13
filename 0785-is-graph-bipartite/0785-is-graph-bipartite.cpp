class Solution {
public:
    bool isDfsBipartite(auto&graph,auto&visited,int u,int colorU){
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
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>visited(n,-1);

        for(int i=0;i<n;i++){
            if(visited[i]==-1){
                if(!isDfsBipartite(graph,visited,i,0)){
                    return false;
                }
            }
        }
        return true;
    }
};