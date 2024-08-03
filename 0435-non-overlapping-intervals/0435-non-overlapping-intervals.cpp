class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int prev=0;
        int curr=1;
        int ans=0;
        sort(intervals.begin(),intervals.end());
        while(curr<intervals.size()){
            if(intervals[curr][0]<intervals[prev][1]){
                //overlapping found
                ans++;
                if(intervals[prev][1]>=intervals[curr][1]){
                    prev=curr;
                    curr++;
                }
                else{
                    curr++;
                }
            }
            else{
                prev=curr;
                curr++;
            }
        }
        return ans;
    }
};