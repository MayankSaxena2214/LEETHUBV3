//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minRemoval(int N, vector<vector<int>> &intervals) {
        // code here
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


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<vector<int>> intervals(N, vector<int>(2));
        for (int i = 0; i < N; i++) {
            cin >> intervals[i][0] >> intervals[i][1];
        }
        Solution obj;
        cout << obj.minRemoval(N, intervals) << endl;
    }
    return 0;
}
// } Driver Code Ends