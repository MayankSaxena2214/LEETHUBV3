//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	    void solve(set<string>&ans,int index,string str){
	        if(index>=str.length()){
	            ans.insert(str);
	            return;
	        }
	        for(int i=index;i<str.length();i++){
	            swap(str[i],str[index]);
	            solve(ans,index+1,str);
	            swap(str[i],str[index]);
	        }
	    }
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    set<string>ans;
		    int index=0;
		    solve(ans,index,S);
		    vector<string>temp(ans.begin(),ans.end());
		    return temp;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    sort(ans.begin(),ans.end());
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends