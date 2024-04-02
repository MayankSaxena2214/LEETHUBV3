class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        priority_queue<int>pq;
        int ans=0;
        for(auto i:nums)pq.push(i);
        while(k){
            int val=pq.top();
            pq.pop();
            ans+=val;
            pq.push(val+1);
            k--;
        }
        return ans;
    }
};