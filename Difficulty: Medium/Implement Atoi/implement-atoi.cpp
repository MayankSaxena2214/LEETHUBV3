//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string s) {
        //Your code h
        bool neg=false;
        if(s[0]=='-'){
            neg=true;
            s=s.substr(1);
        }
        int ans=0;
        for(auto ch:s){
            if(ch>='0' && ch<='9'){
                int digit=ch-'0';
            ans=digit+ans*10;    
            }
            else {
                return -1;
            }
            
        }
        if(neg)return ans*-1;
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
		string s;
		cin>>s;
		Solution ob;
		int ans=ob.atoi(s);
		cout<<ans<<endl;
	}
}
// } Driver Code Ends