//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;
// int maxArea(int A[], int len);

// } Driver Code Ends
//User function template for C++

long long maxArea(long long height[], int len)
{
    // Your code goes here
    long long s=0,n=len,e=n-1;
        int ans=0;
        while(s<e){
            long long fh=height[s];
            long long lh=height[e];
            long long  h=min(fh,lh);
            long long l=e-s;
            if(l*h>ans){
                ans=l*h;
            }
            if(fh>lh){
                e--;
            }
            else{
                s++;
            }
        }
        return ans;
}

//{ Driver Code Starts.

// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
    {
        int n;
        cin>>n;
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<maxArea(arr,n)<<endl;
    }
return 0;
}

// } Driver Code Ends