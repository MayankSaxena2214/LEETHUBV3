class Solution {
  public:
    vector<int> findOrder(int numCourses, vector<vector<int>> prerequisites) {
        // code here
        unordered_map<int,vector<int>>adj;
        for(auto vc:prerequisites){
            int b=vc[1];
            int a=vc[0];
            adj[b].push_back(a);
        }
        vector<int>result;
        //topo is possible or not 
        //if possible we can finish else not
        vector<int>indegree(numCourses,0);
        for(int i=0;i<numCourses;i++){
            for(auto v:adj[i]){
                indegree[v]++;
            }
        }
        int count=0;
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
                count++;
                result.push_back(i);
            }
        }
        while(!q.empty()){
            int u=q.front();
            q.pop();

            for(auto v:adj[u]){
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                    count++;
                    result.push_back(v);
                }
            }
        }
        // cout<<"Count is:"<<count;
        if(count==numCourses)return result;
        return {};
    }
};