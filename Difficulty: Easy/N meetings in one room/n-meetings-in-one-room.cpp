//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(int n, int start[], int end[]) {
        // Your code here
        vector<pair<int,int>>meetings;
        for(int i=0;i<n;i++){
            meetings.push_back({start[i],end[i]});
        }
        sort(meetings.begin(),meetings.end());
        int prev=0;
        int curr=1;
        int ans=0;
        while(curr<n){
            if(meetings[prev].second>=meetings[curr].first){
                //overlapping
                ans++;
                if(meetings[prev].second>=meetings[curr].second){
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
        return n-ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++)
            cin >> start[i];

        for (int i = 0; i < n; i++)
            cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(n, start, end);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends