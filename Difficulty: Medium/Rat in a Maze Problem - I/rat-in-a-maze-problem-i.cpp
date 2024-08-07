//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    bool isSafe(int x,int y,vector<vector<int>> &mat,vector<vector<int>> &visited,int n){
        if((x>=0 && x<n) && (y>=0 && y<n) && (visited[x][y]==0) && mat[x][y]==1){
            return true;
        }
        return false;
    }
    void solve(vector<vector<int>> &mat,vector<vector<int>> &visited,vector<string>&ans,string path,int x,int y,int n){
        if(x==n-1 && y==n-1){
            ans.push_back(path);
            return ;
        }
        visited[x][y]=1;
        //D
        int newx=x+1,newy=y;
        if(isSafe(newx,newy,mat,visited,n)){
            path.push_back('D');
            solve(mat,visited,ans,path,newx,newy,n);
            path.pop_back();
        }
        //L
        newx=x,newy=y-1;
        if(isSafe(newx,newy,mat,visited,n)){
            path.push_back('L');
            solve(mat,visited,ans,path,newx,newy,n);
            path.pop_back();
        }
        //R
        newx=x,newy=y+1;
        if(isSafe(newx,newy,mat,visited,n)){
            path.push_back('R');
            solve(mat,visited,ans,path,newx,newy,n);
            path.pop_back();
        }
        newx=x-1,newy=y;
        if(isSafe(newx,newy,mat,visited,n)){
            path.push_back('U');
            solve(mat,visited,ans,path,newx,newy,n);
            path.pop_back();
        }
        
        
        
        visited[x][y]=0;
    }
    vector<string> findPath(vector<vector<int>> &mat) {
        // Your code goes here
        if(mat[0][0]==0)return {};
        int srcx=0,srcy=0;
        vector<string>ans;
        string path;
        int n=mat.size();
        vector<vector<int>>visited(n,vector<int>(n,0));
        solve(mat,visited,ans,path,srcx,srcy,n);
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