//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &nums, int target) {
        // Your code goes here
        sort(nums.begin(),nums.end());
        set<vector<int>>temp;
        int n=nums.size();
        for(int i=0;i<n-3;i++){
            for(int j=i+1;j<n-2;j++){
                int s=j+1,e=n-1;
                long long more=target-nums[i];
                more-=nums[j];
                while(s<e){
                    long long val=nums[s]+nums[e];
                    if(val==more){
                        temp.insert({nums[i],nums[j],nums[s++],nums[e--]});
                    }
                    else if(val>more){
                        e--;
                    }
                    else {
                        s++;
                    }
                }
            }
        }
        vector<vector<int>>ans(temp.begin(),temp.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends