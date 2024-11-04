class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int row1=matrix.size();
        int col1=matrix[0].size();
        // for(int i=0;i<row1-1;i++){
        //     for(int j=i+1;j<col1;j++){
        //         swap(matrix[i][j],matrix[j][i]);
        //     }
        // }
        // return matrix;
        vector<vector<int>>ans(col1,vector<int>(row1,0));
        for(int i=0;i<row1;i++){
            for(int j=0;j<col1;j++){
                ans[j][i]=matrix[i][j];
            }
        }
        return ans;
    }
};