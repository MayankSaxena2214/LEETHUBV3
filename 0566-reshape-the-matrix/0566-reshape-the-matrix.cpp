class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int row=mat.size();
        int col=mat[0].size();
        if(row*col!=r*c)return mat;
        int x=0,y=0;
        vector<vector<int>>ans(r,vector<int>(c,0));
        for(int i=0;i<row;i++){
            
            for(int j=0;j<col;j++){
                ans[x][y]=mat[i][j];
                y++;
                if(y==c){
                    y=0;
                    x++;
                }
            }
        }
        return ans;
    }
};