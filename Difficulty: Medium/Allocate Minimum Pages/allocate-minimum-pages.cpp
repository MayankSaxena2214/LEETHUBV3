//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template in C++

class Solution {
  public:
    // Function to find minimum number of pages.
    bool isPossible(int*arr,int n,int m,long long mid){
        long long pages=0;
        int student=1;
        for(int i=0;i<n;i++){
            if(pages+arr[i]<=mid){
                pages+=arr[i];
            }
            else{
                student++;
                if(student>m || arr[i]>mid){
                    return false;
                }
                pages=arr[i];
            }
        }
        return true;
    }
    long long findPages(int n, int arr[], int m) {
        // code here
        if(m>n){
            return -1;
        }
        long long s=0,e=accumulate(arr,arr+n,0);
        long long mid=s+(e-s)/2,ans=-1;
        while(s<=e){
            if(isPossible(arr, n,m,mid)){
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
            mid=s+(e-s)/2;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        int m;
        cin >> m;
        Solution ob;
        cout << ob.findPages(n, A, m) << endl;
    }
    return 0;
}

// } Driver Code Ends