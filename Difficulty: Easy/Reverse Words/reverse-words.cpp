//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        // code here 
        stringstream ss(S);
        vector<string>temp;
        string buff;
        while(getline(ss,buff,'.')){
            temp.push_back(buff);
        }
        string ans;
        if(temp.size()==0)return "";
        int n=temp.size();
        for(int i=n-1;i>=0;i--){
            ans+=temp[i];
            ans+='.';
        }
        ans.pop_back();
        return ans;
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends