class Solution {
  public:
    int findDelayTime(int n, vector<vector<int>> &times, int k) {
        // code here
        unordered_map<int,vector<pair<int,int>>>adj;

        for(auto &vec:times){
            int u=vec[0];
            int v=vec[1];
            int w=vec[2];

            adj[u].push_back({v,w});
        }

        vector<int>result(n,INT_MAX);
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

        result[k]=0;
        pq.push({0,k});

        while(!pq.empty()){
            auto pqtop=pq.top();
            pq.pop();
            int u=pqtop.second;
            int dist=pqtop.first;

            for(auto &pr: adj[u]){
                int v=pr.first;
                int d=pr.second;

                if(dist+d<result[v]){
                    result[v]=dist+d;
                    pq.push({dist+d,v});
                }
            }
        }
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            if(result[i]==INT_MAX)return -1;
            maxi=max(maxi,result[i]);
        }

        return maxi;
        
    }
};