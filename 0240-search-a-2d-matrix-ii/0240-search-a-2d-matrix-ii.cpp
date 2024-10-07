class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        int total=rows*cols;
        int start=0,end=total-1;
        int i=0;
        int j=cols-1;
        while(i<rows && cols>=0){
            int value=matrix[i][j];
            if(value==target)return true;
            else if(value>target)j--;
            else i++;
        }
        return false;
    }
};