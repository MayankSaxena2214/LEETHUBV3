//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string str)
    {
        // Your code here
        int maxi=INT_MIN;
        vector<int>v(26,0);
        char ch;
        for(int i=0;i<str.length();i++){
            v[str[i]-'a']++;
           
        }
        for(int i=0;i<26;i++){
             if(v[i]>maxi){
                maxi=v[i];
                ch=i+'a';
            }
        }
        return ch;
        
    }

};

//{ Driver Code Starts.

int main()
{
   
    int t;
    cin >> t;
    while(t--)
    {
        string str;
        cin >> str;
    	Solution obj;
        cout<< obj.getMaxOccuringChar(str)<<endl;
    }
}
// } Driver Code Ends