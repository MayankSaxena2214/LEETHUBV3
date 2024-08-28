//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    bool isPossible(int*boards,int k,long long mid,int n){
    int painter=1;
    long long  time=0;
    for(int i=0;i<n;i++){
        if(boards[i]+time<=mid){
            time+=boards[i];
        }
        else{
            painter++;
            if(painter>k || boards[i]>mid){
                return false;
            }
            time=boards[i];
        }
    }
    return true;
}
    long long minTime(int boards[], int n, int k)
    {
        // code here
        // return minimum time
    long long maxi=INT_MIN;
    long long sum=0;
    for(int i=0;i<n;i++){
        if(boards[i]>maxi)maxi=boards[i];
        sum+=boards[i];
    }
    long long s=maxi;
    long long e=sum;
    
    long long ans=-1;
    while(s<=e){
        long long mid=s+(e-s)/2;
        if(isPossible(boards,k,mid,n)){
            ans=mid;
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}
// } Driver Code Ends