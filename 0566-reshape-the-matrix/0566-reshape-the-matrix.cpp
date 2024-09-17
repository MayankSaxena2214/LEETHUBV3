class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int rows=mat.size();
        int cols=mat[0].size();
        if(r*c!=rows*cols)return mat;
        vector<vector<int>>ans(r,vector<int>(c,0));
        int row=0,col=0;
        for(int i=0;i<rows;i++){
            for(int j =0;j<cols;j++){
                ans[row][col]=mat[i][j];
                col++;
                if(col==c){
                    col=0;
                    row++;
                }

            }
        }
        return ans;
    }
};