class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        // Code here
        queue<int>q;
        q.push(0);
        vector<int>ans;
        vector<bool>visited(adj.size(),false);
        while(!q.empty()){
            int u=q.front();
            q.pop();
            if(visited[u])continue;
            ans.push_back(u);
            visited[u]=true;
            //push its neighbours in queue
            vector<int>neighbours=adj[u];
            for(auto v:neighbours){
                if(!visited[v])
                q.push(v);
            }
        }
        return ans;
    }
};