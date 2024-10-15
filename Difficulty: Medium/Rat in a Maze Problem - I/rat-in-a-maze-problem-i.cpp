//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    bool isSafe(vector<vector<int>> &mat,vector<vector<int>> visited,int x,int y,int n){
        if((x>=0 && x<n) && (y>=0 && y<n) && (visited[x][y]==0) && (mat[x][y]==1))return true;
        return false;
    }
    void solve(vector<vector<int>> &mat,int x,int y,int n,vector<string>&ans,vector<vector<int>>&visited,string& path){
        if(x==n-1 && y==n-1){
            ans.push_back(path);
            return ;
        }
        visited[x][y]=1;
        int newx,newy;
        //DLRU
        //Down
        newx=x+1,newy=y;
        if(isSafe(mat,visited,newx,newy,n)){
            path.push_back('D');
            solve(mat,newx,newy,n,ans,visited,path);
            path.pop_back();
        }
        //L
        newx=x,newy=y-1;
        if(isSafe(mat,visited,newx,newy,n)){
            path.push_back('L');
            solve(mat,newx,newy,n,ans,visited,path);
            path.pop_back();
        }
        //R
        newx=x,newy=y+1;
        if(isSafe(mat,visited,newx,newy,n)){
            path.push_back('R');
            solve(mat,newx,newy,n,ans,visited,path);
            path.pop_back();
        }
        //U
        newx=x-1,newy=y;
        if(isSafe(mat,visited,newx,newy,n)){
            path.push_back('U');
            solve(mat,newx,newy,n,ans,visited,path);
            path.pop_back();
        }
        visited[x][y]=0;
    }
    vector<string> findPath(vector<vector<int>> &mat) {
        // Your code goes here
        vector<string>ans;
        if(mat[0][0]==0)return ans;
        int x=0,y=0;
        int n=mat.size();
        vector<vector<int>> visited(n,vector<int>(n,0));
        string path;
        solve(mat,x,y,n,ans,visited,path);
        return ans;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends