//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int MinRemove(int n, string s);

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << MinRemove(n, s) << endl;
    }
return 0;
}
// } Driver Code Ends


int MinRemove(int n, string s){
    //complete the function here
        if(s.length()==0)return 0;
        int start=0,end=s.length()-1;
        while(start<end){
            if(s[start]!=s[end]){
                return 2;
            }
            start++;
            end--;
        }
        return 1;
}