//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

void toBinary(int N)
{
    // your code here
        int m=N;
        int ans=0;
        int i=0;
        while(m!=0){
            int bit=m&1;
            ans=bit*pow(10,i)+ans;
            
            m=m>>1;
            i++;
        }
        cout<<ans;
}

//{ Driver Code Starts.

int main() {
	//code
	
	int t;
	cin>>t;
	
	
	while(t--)
	{
	    int n;
	    cin>>n;
	    
	    toBinary(n);
	    cout<<endl;
	}
	return 0;
}
// } Driver Code Ends