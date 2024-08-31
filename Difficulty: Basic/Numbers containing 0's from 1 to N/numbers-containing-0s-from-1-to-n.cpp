//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
	public:
	int CountNo(int N)
	{
		// Code 
		int ans=0;
		for(int i=1;i<=N;i++){
		    int num=i;
		    while(num>0){
		        if(num%10==0){
		            ans++;
		            break;
		        }
		        num=num/10;
		    }
		}
		return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.CountNo(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends