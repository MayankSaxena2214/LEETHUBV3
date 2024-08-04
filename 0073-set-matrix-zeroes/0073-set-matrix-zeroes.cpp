class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        //check row 0 and column 0 contain zero or not
        int x=0,y=0;
        int row=matrix.size();
        int col=matrix[0].size();
        for(int i=0;i<col;i++){
            if(matrix[0][i]==0)x=1;
        }
        
        for(int i=0;i<row;i++){
            if(matrix[i][0]==0)y=1;
        }
        //mark the zero
        for(int i=1;i<row;i++){
            for(int j=1;j<col;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        //make zeroes for marked
        for(int i=1;i<col;i++){
            if(matrix[0][i]==0){
                for(int j=1;j<row;j++){
                    matrix[j][i]=0;
                }
            }
        }
        for(int i=1;i<row;i++){
            if(matrix[i][0]==0){
                for(int j=1;j<col;j++){
                    matrix[i][j]=0;
                }
            }
        }
        //process row 0 and col0
        if(x==1){
            for(int j=0;j<col;j++){
                matrix[0][j]=0;
            }
        }
        if(y==1){
            for(int i=0;i<row;i++){
                matrix[i][0]=0;
            }
        }
    }
};