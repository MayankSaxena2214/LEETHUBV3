class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int maxreach=startFuel;
        priority_queue<int>pq;
        int count=0;
        int index=0;
        int n=stations.size();
        while(maxreach<target){
            while(index<n && stations[index][0]<=maxreach){
                pq.push(stations[index][1]);
                index++;
            }
            if(pq.empty())return -1;
            maxreach+=pq.top();
            pq.pop();
            count++;
        }
        return count;
    }
};