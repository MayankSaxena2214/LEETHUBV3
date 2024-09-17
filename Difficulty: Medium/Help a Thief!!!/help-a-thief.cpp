//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int maxCoins(int A[], int B[], int T, int N) {
        // code here
        set<pair<int,int>, greater<pair<int,int>>>st;
        for(int i=0;i<N;i++){
            st.insert({B[i],A[i]});
        }
        int ans=0;
        while(!st.empty() && T){
            auto it=st.begin();
            int coins=it->first;
            int plates=it->second;
            ans+=coins*min(T,plates);
            T-=min(T,plates);
            
            st.erase(st.begin());
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int T,N;
        cin>>T>>N;
        
        int A[N], B[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];
        for(int i=0; i<N; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.maxCoins(A,B,T,N) << endl;
    }
    return 0;
}
// } Driver Code Ends