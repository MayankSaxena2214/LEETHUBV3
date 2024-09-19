//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to reverse words in a given string.
    string reverseWords(string str) {
        // code here
        string curr;
        vector<string>ans;
        int index=0;
        for(auto ch:str){
            if(ch=='.'){
                ans.push_back(curr);
                curr="";
            }
            else{
                curr+=ch;
            }
            if(index==str.length()-1){
                ans.push_back(curr);
                curr="";
            }
            index++;
        }
        
        
        for(int i=ans.size()-1;i>=0;i--){
            if(i==0){
                curr+=ans[i];
            }    
            else{
                curr+=ans[i];
                curr+='.';
            }
        }
        return curr;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.reverseWords(s) << endl;
    }
}
// } Driver Code Ends