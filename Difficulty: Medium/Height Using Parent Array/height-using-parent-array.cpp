//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    int findHeight(int N, int arr[]){
        // code here
        int ans=0;
        for(int i=0;i<N;i++){
            int temp=1;
            int value=arr[i];
            while(value!=-1){
                temp++;
                value=arr[value];
            }
            ans=max(ans,temp);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.findHeight(N, arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends