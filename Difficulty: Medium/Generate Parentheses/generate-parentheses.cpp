//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


// } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    void solve(vector<string>&ans,string str,int open,int close,int n){
        if(open==n && close==n){
            ans.push_back(str);
            return;
        }
        if(open<n){
            str.push_back('(');
            solve(ans,str,open+1,close,n);
            str.pop_back();
        }
        if(close<open){
            str.push_back(')');
            solve(ans,str,open,close+1,n);
            str.pop_back();
        }
}
    vector<string> AllParenthesis(int n) 
    {
        // Your code goes here 
        int open=0,close=0;
        vector<string>ans;
        string str;
        solve(ans,str,open,close,n);
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
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 

// } Driver Code Ends