//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string a, string b){
        
        // Your code here
        vector<int>v1(26,0);
        vector<int>v2(26,0);
        for(auto val:a)v1[val-'a']++;
        for(auto val:b)v2[val-'a']++;
        for(int i=0;i<26;i++){
            if(v1[i]!=v2[i])return false;
        }
        return true;
    }

};

//{ Driver Code Starts.

int main() {
    
    int t;

    cin >> t;

    while(t--){
        string c, d;

        cin >> c >> d;
        Solution obj;
        if(obj.isAnagram(c, d)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}

// } Driver Code Ends