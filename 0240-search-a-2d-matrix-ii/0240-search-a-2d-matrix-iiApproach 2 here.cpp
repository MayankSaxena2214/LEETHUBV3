class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //Approach 1
         int row=matrix.size();
        int col=matrix[0].size();
        int rowindex=row-1;
        int colindex=0;
        while(rowindex>=0 && colindex<col){
            int element=matrix[rowindex][colindex];
            if(element==target){
                return true;
            }
            else if(element>target){
                rowindex--;
            }
            else{
                colindex++;
            }
        }
        return false;

        //Approach 2
        // int row=matrix.size();
        // int col=matrix[0].size();
        // int rowindex=0;
        // int colindex=col-1;
        // while(rowindex<row && colindex>=0){
        //     int element=matrix[rowindex][colindex];
        //     if(element==target){
        //         return true;
        //     }
        //     else if(element>target){
        //         colindex--;
        //     }
        //     else{
        //         rowindex++;
        //     }
        // }
        // return false;
    }
};