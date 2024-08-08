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
        vector<int>v(26,0);
        int maxi=INT_MIN;
        int index=-1;
        for(auto ch:str){
            v[ch-'a']++;
            
        }
        for(int i=0;i<26;i++){
            if(v[i]>maxi){
                maxi=v[i];
                index=i;
            }
        }
        return 'a'+index;
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