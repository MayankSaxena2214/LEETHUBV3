//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// #define ll long long
class Solution{
public:
    
    vector<long long> nthRowOfPascalTriangle(int n) {
        // code here
        const int M=1e9+7;
        vector<vector<long long>>ans;
        for(int i=0;i<n;i++){
            vector<long long>temp(i+1,1);
            
            for(int j=1;j<i;j++){
                int val=ans[i-1][j-1]+ans[i-1][j];
                temp[j]=val%M;
            }
            ans.push_back(temp);
        }
        return ans[n-1];
    }
};


//{ Driver Code Starts.


void printAns(vector<long long> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends