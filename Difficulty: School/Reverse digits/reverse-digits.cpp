//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
		long long int reverse_digit(long long int n)
		{
		    // Code here
		    long long int ans=0;
		    bool first=true;
		    while(n!=0){
		        int digit=n%10;
		        if(digit==0 && first==true){
		            n=n/10;
		            continue;
		        }
		        else{
		            ans=ans*10+digit;
		            first=false;
		            n=n/10;
		        }
		    }
		    return ans;
		}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	long long int n;
    	cin >> n;
    	Solution ob;
    	long long int  ans = ob.reverse_digit(n);
    	cout << ans <<"\n";
    }
	return 0;
}
// } Driver Code Ends