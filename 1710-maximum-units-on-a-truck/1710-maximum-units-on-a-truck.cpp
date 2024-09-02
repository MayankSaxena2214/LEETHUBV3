class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        priority_queue<pair<int,int>>pq;
        int n=boxTypes.size();
        for(int i=0;i<n;i++){
            pq.push({boxTypes[i][1],boxTypes[i][0]});
        }
        int sum=0;
        int count=0;
        while(!pq.empty() && count<truckSize){
            if(pq.top().second+count<truckSize){
                count+=pq.top().second;
                int value=pq.top().first*pq.top().second;
                sum+=value;
                pq.pop();
                
            }
            else{
                int quantity=truckSize-count;
                count+=quantity;
                int value=pq.top().first*quantity;
                sum+=value;
                pq.pop();
            }
        }
        return sum;
    }
};