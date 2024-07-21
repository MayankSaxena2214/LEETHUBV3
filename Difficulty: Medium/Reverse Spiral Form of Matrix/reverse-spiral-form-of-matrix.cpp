//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> reverseSpiral(int r, int c, vector<vector<int>>&matrix)  {
        // code here
        int rowst=0,rowend=r-1,colst=0,colend=c-1;
        int total=r*c;
        int count=0;
        vector<int>ans;
        while(count<total){
            for(int col=colst;col<=colend&& count < total;col++){
                ans.push_back(matrix[rowst][col]);
                count++;
            }
            rowst++;
            for(int row=rowst;row<=rowend&& count < total;row++){
                ans.push_back(matrix[row][colend]);
                count++;
            }
            colend--;
            for(int col=colend;col>=colst&& count < total;col--){
                ans.push_back(matrix[rowend][col]);
                count++;
            }
            rowend--;
            for(int row=rowend;row>=rowst&& count < total;row--){
                ans.push_back(matrix[row][colst]);
                count++;
            }
            colst++;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, C;
        cin>>R>>C;
        vector<vector<int>> a(R, vector<int>(C, 0));
        for(int i = 0;i < R*C;i++)
            cin>>a[i/C][i%C];
        Solution ob;
        vector<int>ans=ob.reverseSpiral(R,C,a);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
            cout<<endl;
    }
    return 0;
}

// } Driver Code Ends