//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    int leftOccurence(int*arr,int s,int e,int k){
        
        int mid;
        mid=s+(e-s)/2;
        int ans=-1;
        while(s<=e){
            if(arr[mid]==k){
                ans=mid;
                e=mid-1;
            }
            else if(arr[mid]>k){
                e=mid-1;
            }
            else s=mid+1;
            mid=s+(e-s)/2;
        }
        return ans;
    }
     int rightOccurence(int*arr,int s,int e,int k){
        
        int mid;
        mid=s+(e-s)/2;
        int ans=-1;
        while(s<=e){
            if(arr[mid]==k){
                ans=mid;
                s=mid+1;
            }
            else if(arr[mid]>k){
                e=mid-1;
            }
            else s=mid+1;
            mid=s+(e-s)/2;
        }
        return ans;
    }
    
    vector<int> find(int arr[], int n , int x )
    {
        // code here
        int l=leftOccurence(arr,0,n-1,x);
        int r=rightOccurence(arr,0,n-1,x);
        vector<int>temp={l,r};
        return temp;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends