//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) {
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
        vector<vector<int> > matrix(r);

        for (int i = 0; i < r; i++) {
            matrix[i].assign(c, 0);
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends