//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    string findAndReplace(string S ,int Q, int index[], string sources[], string targets[]) {
        // code here
        int newLength=0;
        string original=S;
        for(int i=0;i<Q;i++){
            
            auto found=original.find(sources[i]);
            
            while(found!=string::npos){
                if(found==index[i]){
                    S.replace(found+newLength,sources[i].length(),targets[i]);
                    newLength+=targets[i].length()-sources[i].length();
                    
                }
                found=original.find(sources[i],found+1);
                
            }
        }
        return S;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        
        int Q;
        cin>>Q;
        int index[Q];
        string sources[Q], targets[Q];
        
        for(int i=0; i<Q; i++)
            cin>>index[i];
        for(int i=0; i<Q; i++)
            cin>>sources[i];
        for(int i=0; i<Q; i++)
            cin>>targets[i];

        Solution ob;
        cout<<ob.findAndReplace(S,Q,index,sources,targets)<<endl;
    }
    return 0;
}
// } Driver Code Ends