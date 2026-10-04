class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        int total=rows*cols;
        int low=0;
        int end=cols-1;
       while(low<rows && end>=0){
        int val=matrix[low][end];
        if(val==target)return true;
        else if(val>target)end--;
        else low++;
       }
       return false;
    }
};