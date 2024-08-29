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
        vector<int>count(26,0);
        char ans;
        int maxi=-1;
    
        for(auto ch:str){
            count[ch-'a']++;
            
        }
        for(int i=0;i<26;i++){
            if(count[i]>maxi){
                maxi=count[i];
                ans=i+'a';
            }
        }
        return ans;
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