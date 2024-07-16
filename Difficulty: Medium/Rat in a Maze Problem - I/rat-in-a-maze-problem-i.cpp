//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    bool isSafe(int x,int y,vector < vector < int >> & arr,vector < vector < int >> & visited,int n){
    if((x>=0 && x<n) && (y>=0 && y<n) && (visited[x][y]==0) && arr[x][y]==1){
        return true;
    }
    return false;
}
void solve(vector < vector < int >> & arr,vector < vector < int >> &visited,vector<string>&ans,string path,int srcx,int srcy,int n){
    if(srcx==n-1 && srcy==n-1){
        ans.push_back(path);
        return;
    }
    visited[srcx][srcy]=1;
    //DLRU
    //down
    int newx=srcx+1,newy=srcy;
    if(isSafe(newx,newy,arr,visited,n)){
        path.push_back('D');
        solve(arr,visited,ans,path,newx,newy,n);
        path.pop_back();
    }
    //left
    newx=srcx,newy=srcy-1;
    if(isSafe(newx,newy,arr,visited,n)){
        path.push_back('L');
        solve(arr,visited,ans,path,newx,newy,n);
        path.pop_back();
    }
    //Right
    newx=srcx,newy=srcy+1;
    if(isSafe(newx,newy,arr,visited,n)){
        path.push_back('R');
        solve(arr,visited,ans,path,newx,newy,n);
        path.pop_back();
    }
    newx=srcx-1,newy=srcy;
    if(isSafe(newx,newy,arr,visited,n)){
        path.push_back('U');
        solve(arr,visited,ans,path,newx,newy,n);
        path.pop_back();
    }

    visited[srcx][srcy]=0;
}
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
         vector<vector<int>>visited(n,vector<int>(n,0));
    vector<string>ans;
    string path;
    if(m[0][0]==0)return ans;
    int srcx=0,srcy=0;
    solve(m,visited,ans,path,srcx,srcy,n);
    sort(ans.begin(),ans.end());
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
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends