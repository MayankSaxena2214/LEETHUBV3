//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends


int countRev (string s)
{
    // your code here
    stack<int>st;
    for(int i=0;i<s.length();i++){
        if(s.length()%2!=0)return -1;
        char ch=s[i];
        if(ch=='{'){
            st.push(ch);
        }
        else{
            if(st.empty()){
                st.push(ch);
            }
            else{
                if(st.top()=='{'){
                    st.pop();
                }
                else{
                    st.push(ch);
                }
            }
        }
    }
    int a=0;
    int b=0;
    while(!st.empty()){
        char ch=st.top();
        st.pop();
        if(ch=='{')a++;
        if(ch=='}')b++;
        
    }
    return ((a+1)/2 + (b+1)/2);
}