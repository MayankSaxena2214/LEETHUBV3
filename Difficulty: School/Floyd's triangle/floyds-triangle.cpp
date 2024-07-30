//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    void printFloydTriangle(int N)
    {
        // Write Your Code here
        int i=1;
        int count=1;
        while(i<=N){
            int j=1;
            while(j<=i){
                cout<<count<<" ";
                count++;
                j++;
            }
            cout<<endl;
            i++;
        }
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        Solution ob;
        ob.printFloydTriangle(N);
    }
    return 0;
}
// } Driver Code Ends