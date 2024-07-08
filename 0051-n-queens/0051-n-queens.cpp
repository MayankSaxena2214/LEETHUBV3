class Solution {
public:
    void addSolution(vector<vector<char>>board,vector<vector<string>>&ans,int n){
        vector<string>temp;
        for(int i=0;i<n;i++){
            string curr="";
            for(int j=0;j<n;j++){
                curr+=board[i][j];

            }
            temp.push_back(curr);
        }
        ans.push_back(temp);
        
    }
    bool isSafe(int row,int col,vector<vector<char>>board,int n){
        int x=row,y=col;
        while(y>=0){
            if(board[x][y]=='Q'){
                return false;
            }
            y--;
        }
        x=row,y=col;
        while(x>=0 && y>=0){
            if(board[x][y]=='Q'){
                return false;
            }
            x--;
            y--;
        }
        x=row,y=col;
        while(x<n && y>=0){
            if(board[x][y]=='Q'){
                return false;
            }
            x++;
            y--;
        }
        return true;
    }
    void solve(vector<vector<char>>board,vector<vector<string>>&ans,int col,int n){
        if(col==n){
            addSolution(board,ans,n);
            return;
        }
        for(int row=0;row<n;row++){
            if(board[row][col]=='.'){
                if(isSafe(row,col,board,n)){
                    board[row][col]='Q';
                    solve(board,ans,col+1,n);
                    board[row][col]='.';
                }
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>>board(n,vector<char>(n,'.'));
        vector<vector<string>>ans;
        int index=0;
        solve(board,ans,index,n);
        return ans;
    }
};