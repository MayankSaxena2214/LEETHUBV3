//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseWords (string str)
    {
        //code here.
         int i=0;
    int st=0;
    while(i<str.length()){
        if(str[i]=='.'){
            if(st<i-1){
                int p=st;
                int q=i-1;
                while(p<q){
                    swap(str[p],str[q]);
                    p++,q--;
                }
                st=i+1; 
            }
            else{
                st=i+1;
            }
        }
        i++;
    }
    int p=st;
                int q=i-1;
                while(p<q){
                    swap(str[p],str[q]);
                    p++,q--;
                }
    
    return str;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.reverseWords (s) << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends