class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        int total=rows*cols;
        int s=0,e=total-1;
        int mid=(s+e)/2;
        while(s<=e){
            int val=matrix[mid/cols][mid%cols];
            if(val==target)return true;
            else if(val>target){
                e=mid-1;
            }
            else s=mid+1;
            mid=(s+e)/2;
        }
        return false;
    }
};