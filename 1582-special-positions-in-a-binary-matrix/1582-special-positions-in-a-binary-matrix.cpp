class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int row=mat.size();
        int ans=0;
        int col=mat[0].size();
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==1){
                    int rowcount=0,colcount=0;
                    for(int p=0;p<col;p++){
                        if(mat[i][p]==0){
                            rowcount++;
                        }
                    }
                    
                    for(int q=0;q<row;q++){
                        if(mat[q][j]==0)colcount++;
                    }
                    if(rowcount==col-1 && colcount==row-1)ans++;

                }
            }
        }
        return ans;
    }
};