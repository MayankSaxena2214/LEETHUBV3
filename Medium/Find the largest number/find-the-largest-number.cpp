//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    
    int find(int N){
        // code here
        for(int i=N;i>=0;i--){
            string num=to_string(i);
            bool flag=true;
            for(int i=0;i<num.length();i++){
                if(i+1<num.length() && num[i]>num[i+1]){
                    flag=false;
                    break;
                }
            }
            if(flag==true){
                return i;
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.find(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends