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
        char ans;
        int maxicnt=0;
        vector<int>v(26,0);
        for(auto ch:str){
            int index=ch-'a';
            v[index]++;
        }
        for(int i=0;i<26;i++){
            if(v[i]>maxicnt){
                maxicnt=v[i];
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