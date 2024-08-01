//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &matrix) {
        // code here
        vector<int>ans;
        int row=matrix.size();
        int col=matrix[0].size();
        int rowst=0,rowend=row-1;
        int colst=0,colend=col-1;
        int total=row*col;
        int count=0;
        while(count!=total){
            for(int i=colst;i<=colend&&count<total;i++){
                ans.push_back(matrix[rowst][i]);
                count++;
            }
            rowst++;
            for(int i=rowst;i<=rowend && count<total;i++){
                ans.push_back(matrix[i][colend]);
                count++;
            }
            colend--;
            for(int i=colend;i>=colst && count<total;i--){
                ans.push_back(matrix[rowend][i]);
                count++;
            }
            rowend--;
            for(int i=rowend;i>=rowst && count<total;i--){
                ans.push_back(matrix[i][colst]);
                count++;
            }
            colst++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c, 0));

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends