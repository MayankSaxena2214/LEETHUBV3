//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
		long long int PowMod(long long int x,long long int n,long long int m)
		{
		    // Code here
		    if(n==0)return 1;
	if(n==1)return x%m;
	long long int temp=PowMod(x,n/2,m);
	if(n%2!=0){
		return (((temp*temp)%m)*x)%m;
	}
	else {
		return (temp*temp)%m;
	}
		}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	long long int x, n, m;
    	cin >> x >> n >> m;
    	Solution ob;
    	long long int ans = ob.PowMod(x, n, m);
    	cout << ans <<"\n";
    }
	return 0;
}

// } Driver Code Ends