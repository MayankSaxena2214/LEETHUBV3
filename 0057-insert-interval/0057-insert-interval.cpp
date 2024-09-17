class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        int n=intervals.size();
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end());
        if(n==0)return ans;
        ans.push_back(intervals[0]);
        for(int i=1;i<n;i++){
            auto&v=ans.back();
            if(v[1]>=intervals[i][0]){
                v[1]=max(v[1],intervals[i][1]);
            }
            else{
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};