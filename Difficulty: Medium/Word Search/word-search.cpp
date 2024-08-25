//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool solve(auto&board,string word,int i,int j,int index){
        if(index>=word.length())return true;
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || word[index]!=board[i][j]){
            return false;
        }
        char temp=board[i][j];
        board[i][j]='*';

        bool left=solve(board,word,i,j-1,index+1);
        bool right=solve(board,word,i,j+1,index+1);
        bool top=solve(board,word,i-1,j,index+1);
        bool bottom=solve(board,word,i+1,j,index+1);

        bool ans=left|| right|| top|| bottom;
        board[i][j]=temp;
        return ans;
    }
    bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0] && solve(board,word,i,j,0)){
                    return true;
                }
            }
        }
        return false;
    }
    
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends