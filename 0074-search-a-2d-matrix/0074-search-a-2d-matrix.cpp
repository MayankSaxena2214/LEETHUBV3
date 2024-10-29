class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        int total=rows*cols;
        int start=0,end=total-1;
        while(start<=end){
            int mid=(start+(end-start)/2);
            int value=matrix[mid/cols][mid%cols];
            if(value==target)return true;
            else if(value>target)end=mid-1;
            else start=mid+1;
        }
        return false;
    }
};