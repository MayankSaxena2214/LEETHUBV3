//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution {
  public:
    long long int floorSqrt(long long int n) {
        // Your code goes here
        if(n==1)return 1;
        long long int s=0,e=n;
        long long int ans=0;
        long long int mid=(s+e)/2;
        while(s<=e){
            long long int square=mid*mid;
            if(square==n)return mid;
            if(square<n){
                ans=mid;
                s=mid+1;
            }
            else{
                e=mid-1;
            }
            mid=(s+e)/2;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        Solution obj;
        cout << obj.floorSqrt(n) << endl;
    }
    return 0;
}

// } Driver Code Ends