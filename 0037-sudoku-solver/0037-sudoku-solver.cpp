class Solution {
public:
    bool isSafe(vector<vector<char>>& sudoku,int row,int col,int val){
    for(int i=0;i<9;i++){
        //row check
        if(sudoku[row][i]==val-1+'1'){
            return false;
        }
        if(sudoku[i][col]==val-1+'1'){
            return false;
        }
        //box check
        if(sudoku[3*(row/3)+i/3][3*(col/3)+i%3]==val-1+'1'){
            return false;
        }
    }
    return true;
    //
}
    bool solve(vector<vector<char>>& sudoku){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(sudoku[i][j]=='.'){
                    for(int val=1;val<=9;val++){
                        if(isSafe(sudoku,i,j,val)){
                            sudoku[i][j]=val-1+'1';
                            if(solve(sudoku))return true;
                        
                            else sudoku[i][j]='.';
                        }
                    }
                return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};