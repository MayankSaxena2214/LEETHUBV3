//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    bool isPossible(vector<int>&stalls,int n,int k,int mid){
        int cow=1;
        int lastpos=stalls[0];
        for(int i=0;i<n;i++){
            if(stalls[i]-lastpos>=mid){
                cow++;
                if(cow==k)return true;
                lastpos=stalls[i];
            }
        }
        return false;
    }
    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        int s=0,e;
        int maxi=*max_element(stalls.begin(),stalls.end());
        int mini=*min_element(stalls.begin(),stalls.end());
        sort(stalls.begin(),stalls.end());
        e=maxi-mini;
        int ans=-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(isPossible(stalls,n,k,mid)){
                ans=mid;
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends