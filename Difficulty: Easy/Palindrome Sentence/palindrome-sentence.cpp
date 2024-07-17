//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	bool sentencePalindrome(string s) 
	{
	    // code here 
	    string temp;
	    for(int i=0;i<s.length();i++){
	        if(s[i]>='a' && s[i]<='z'){
	            temp.push_back(s[i]);
	        }
	    }
	    int st=0,e=temp.length()-1;
	    while(st<e){
	        if(temp[st]!=temp[e])return 0;
	        st++;
	        e--;
	    }
	    return 1;
	}
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    cin.ignore();
    while(t--)
    {
        string str;
        getline(cin,str);
        Solution ob;
        cout<<ob.sentencePalindrome(str)<<endl;
    }
    return 0;
}  


// } Driver Code Ends