//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/* The function returns 1 if
IP string is valid else return 0
You are required to complete this method */
class Solution {
  public:
    int isValid(string str) {
        // code here
        if(str.length()>15)return false;
        string check;
        for(auto ch:str){
            if(ch=='.'){
                if(check.length()>3)return false;
                int num=stoi(check);
                if(num<0 || num>255)return false;
                check="";
            }
            else{
                check+=ch;
            }
        }
        if(check.length()>3)return false;
                int num=stoi(check);
                if(num<0 || num>255)return false;
                check="";
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        // if (s.size() == 3) {
        //     cout << "false" << endl;
        //     return 0;
        // }
        Solution ob;
        bool f = ob.isValid(s);
        if (f)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends