class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        int total=rows*cols;
        int low=0;
        int end=total-1;
        while(low<=end){
            int mid=low+(end-low)/2;
            int element=matrix[mid/cols][mid%cols];
            if(element==target)return true;
            else if(element<target){
                low=mid+1;

            }
            else{
                end=mid-1;
            }
        }
        return false;
    }
};