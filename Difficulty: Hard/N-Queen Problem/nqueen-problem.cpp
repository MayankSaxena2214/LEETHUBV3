//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

bool isSafe(int row,int col,vector<vector<int>>&board,int n){
    //check backward 
    int newr=row,newc=col;
    while(newc>=0){
        if(board[newr][newc]==1)return false;
        newc--;
    }
    newr=row;
    newc=col;
    while(newr>=0 && newc>=0){
        if(board[newr][newc]==1)return false;
        newr--;
        newc--;
    }
    newr=row;
    newc=col;
    while(newr<n && newc>=0){
        if(board[newr][newc]==1)return false;
        newr++;
        newc--;
    }
    return true;
}
void solve(vector<vector<int>>&ans,vector<vector<int>>&board,int i,int n){
    if(i==n){
        vector<int>temp;
    for(int col=0;col<n;col++){
        for(int row=0;row<n;row++){
            if(board[row][col]==1){
                temp.push_back(row+1);
            }
            
        }
    }
    ans.push_back(temp);
    return;
    }
    for(int row=0;row<n;row++){
        if(isSafe(row,i,board,n)){
            board[row][i]=1;
            
            solve(ans,board,i+1,n);
            board[row][i]=0;
        }
    }
}

class Solution{
public:
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<int>>ans;
    
    vector<vector<int>>board(n,vector<int>(n,0));
    int i=0;
    solve(ans,board,i,n);
    return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends