//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    bool isMatch(char ch,char top){
        if((ch=='(' && top==')')||(ch=='{' && top=='}')||(ch=='[' && top==']'))return true;
        return false;
    }
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        stack<char>st;
        for(int i=0;i<x.length();i++){
            char ch=x[i];
            if(ch=='(' || ch=='{' || ch=='['){
                st.push(ch);
            }
            else{
                if(st.empty())return false;
                else{
                    char top=st.top();
                    st.pop();
                    if(isMatch(top,ch)){
                        continue;
                    }
                    else{
                        return false;
                    }
                }
            }
        }
        if(st.empty())return true;
        return false;
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends