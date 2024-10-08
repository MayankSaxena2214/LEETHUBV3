//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    bool isSafe(vector<vector<int>> &mat,vector<vector<int>> &visited,int x,int y,int n){
        if((x>=0 && x<n) && (y>=0 && y<n) && mat[x][y]==1 && visited[x][y]==0){
            return true;
        }
        return false;
    }
    void solve(vector<vector<int>> &mat,vector<vector<int>> &visited,vector<string>&ans,string path,int x,int y,int n){
        if(x==n-1 && y==n-1){
            ans.push_back(path);
            return;
        }
        visited[x][y]=1;
        //DLRU
        int newx=x+1,newy=y;
        if(isSafe(mat,visited,newx,newy,n)){
            path.push_back('D');
            solve(mat,visited,ans,path,newx,newy,n);
            path.pop_back();
        }
        newx=x,newy=y-1;
        if(isSafe(mat,visited,newx,newy,n)){
            path.push_back('L');
            solve(mat,visited,ans,path,newx,newy,n);
            path.pop_back();
        }
        newx=x,newy=y+1;
        if(isSafe(mat,visited,newx,newy,n)){
            path.push_back('R');
            solve(mat,visited,ans,path,newx,newy,n);
            path.pop_back();
        }
        newx=x-1,newy=y;
        if(isSafe(mat,visited,newx,newy,n)){
            path.push_back('U');
            solve(mat,visited,ans,path,newx,newy,n);
            path.pop_back();
        }
        
        
        
        visited[x][y]=0;
    }
    vector<string> findPath(vector<vector<int>> &mat) {
        // Your code goes here
        int n=mat.size();
        vector<string>ans;
        string path;
        int x=0,y=0;
        if(mat[x][y]==0)return {};
        vector<vector<int>>visited(mat.size(),vector<int>(mat[0].size(),0));
        solve(mat,visited,ans,path,x,y,n);
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