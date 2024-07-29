class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        //set markers for 0 row and 0 column
        int x=0,y=0;
        int row=matrix.size();
        int col=matrix[0].size();
        for(int i=0;i<col;i++){
            if(matrix[0][i]==0)x=1;
        }
        for(int i=0;i<row;i++){
            if(matrix[i][0]==0)y=1;
        }
        //set markers in the first row for the remaining matrix
        for(int i=1;i<row;i++){
            for(int j=1;j<col;j++){
                if(matrix[i][j]==0){
                    matrix[0][j]=0;
                    matrix[i][0]=0;
                }
            }
        }
        //proceassing from first row
        for(int j=1;j<col;j++){
            if(matrix[0][j]==0){
                for(int i=0;i<row;i++){
                    matrix[i][j]=0;
                }
            }
        }
        for(int i=1;i<row;i++){
            if(matrix[i][0]==0){
                for(int j=0;j<col;j++){
                    matrix[i][j]=0;
                }
            }
        }
        if(x){
            for(int j=0;j<col;j++){
                matrix[0][j]=0;
            }
        }
        if(y){
            for(int i=0;i<row;i++){
                matrix[i][0]=0;
            }
        }
        
    }
};