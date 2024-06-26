//{ Driver Code Starts


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int findCoverage(vector<vector<int>>& matrix) {
        // Code here
        int ans=0;
        int row=matrix.size();
        int col=matrix[0].size();
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    //checkleft
                    if(j-1>=0 && matrix[i][j-1]==1)ans++;
                    //check right
                    if(j+1<col && matrix[i][j+1]==1)ans++;
                    //check up
                    if(i-1>=0 && matrix[i-1][j]==1)ans++;
                    //check bottom
                    if(i+1<row && matrix[i+1][j]==1)ans++;
                }
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> matrix[i][j];
        Solution obj;
        int ans = obj.findCoverage(matrix);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends