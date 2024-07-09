//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    vector<long long>prevSmaller(long long arr[],int n){
        vector<long long>ans(n);
        stack<long long>st;
        st.push(-1);
        for(int i=0;i<n;i++){
            long long curr=arr[i];
            while(st.top()!=-1 && arr[st.top()]>=curr){
                st.pop();
            }
            if(st.top()==-1)ans[i]=-1;
            else{
                ans[i]=st.top();
            }
            st.push(i);
        }
        return ans;
    }
    vector<long long>nextSmaller(long long arr[],int n){
        vector<long long>ans(n);
        stack<long long>st;
        st.push(-1);
        for(int i=n-1;i>=0;i--){
            long long curr=arr[i];
            while(st.top()!=-1 && arr[st.top()]>=curr){
                st.pop();
            }
            ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        vector<long long>prev;
        prev=prevSmaller(arr,n);
        vector<long long>next;
        next=nextSmaller(arr,n);
        long long area=INT_MIN;
        for(int i=0;i<n;i++){
            long long l=arr[i];
            if(next[i]==-1){
                next[i]=n;
            }
            long long b=next[i]-prev[i]-1;
            area=max(area,l*b);
            
        }
        return area;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends