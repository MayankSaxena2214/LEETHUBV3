//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        vector<long long>ans(n,-1);
        stack<long long>st;
        for(long long i=n-1;i>=0;i--){
            long long curr=arr[i];
            while(!st.empty() && arr[st.top()]<=curr)st.pop();
            if(st.empty()){
                ans[i]=-1;
                
            }
            else {
                ans[i]=arr[st.top()];
                
            }
            st.push(i);
            
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
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends