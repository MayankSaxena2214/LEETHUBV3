//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    bool isSafe(vector<vector<int>>&mat,vector<vector<int>>&visited,int x,int y){
        int n=mat.size();
        if((x>=0 && x<n) && (y>=0 && y<n) && (mat[x][y]==1) && (visited[x][y]==0)){
            return true;
        }
        return false;
    }
    void solve(vector<vector<int>>&mat,vector<string>&ans,string output,int x,int y,vector<vector<int>>&visited,int n){
        if(x==n-1 && y==n-1){
            ans.push_back(output);
            return;
        }          
        visited[x][y]=1;
        //DLRU
        //Down
        int newx,newy;
        newx=x+1,newy=y;
        if(isSafe(mat,visited,newx,newy)){
            output.push_back('D');
            solve(mat,ans,output,newx,newy,visited,n);
            output.pop_back();
        }
        //Left
        newx=x,newy=y-1;
        if(isSafe(mat,visited,newx,newy)){
            output.push_back('L');
            solve(mat,ans,output,newx,newy,visited,n);
            output.pop_back();
        }
        
        //Righnt
        newx=x,newy=y+1;
        if(isSafe(mat,visited,newx,newy)){
            output.push_back('R');
            solve(mat,ans,output,newx,newy,visited,n);
            output.pop_back();
        }
        
        //Up
        newx=x-1,newy=y;
        if(isSafe(mat,visited,newx,newy)){
            output.push_back('U');
            solve(mat,ans,output,newx,newy,visited,n);
            output.pop_back();
        }
        
        
        visited[x][y]=0;
    }
    vector<string> findPath(vector<vector<int>> &mat) {
        // Your code goes here
        vector<string>ans;
        if(mat[0][0]==0)return ans;
        int x=0,y=0;
        int n=mat.size();
        string path;
        vector<vector<int>> visited(n,vector<int>(n,0));
        solve(mat,ans,path,x,y,visited,n);
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