//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to check if a string is Pangram or not.
    bool checkPangram (string s) {
        // your code here
        unordered_map<char,bool>mp;
        for(auto ch:s){
            if(ch>='a' && ch<='z'){
                mp[ch]=true;
            }
            else if(ch>='A' && ch<='Z'){
                char low=ch-'A'+'a';
                mp[low]=true;
            }
        }
        return mp.size()==26;
    }

};

//{ Driver Code Starts.

// Driver Program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--){
        string s;
        getline(cin, s);
        Solution obj;
        if (obj.checkPangram(s) == true)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
    return(0);
}

// } Driver Code Ends