class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        int prev=0,curr=1;
        int count=0;
        sort(intervals.begin(),intervals.end());
        while(curr<n){
            if(intervals[prev][1]>intervals[curr][0]){
                count++;
                //which to removde
                if(intervals[prev][1]>intervals[curr][1]){
                    //delete prev
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
        return count;
    }
};