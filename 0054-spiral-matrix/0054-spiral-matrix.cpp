class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        int total=row*col;
        int count=0;
        int rowSt=0,rowEnd=row-1;
        int colSt=0,colEnd=col-1;
        vector<int>ans;
        while(count<total){
            //rowst print
            for(int j=colSt;j<=colEnd && count<total;j++){
                ans.push_back(matrix[rowSt][j]);
                count++;
            }
            rowSt++;

            for(int i=rowSt;i<=rowEnd && count<total;i++){
                ans.push_back(matrix[i][colEnd]);
                count++;
            }
            colEnd--;

            for(int j=colEnd;j>=colSt && count<total;j--){
                ans.push_back(matrix[rowEnd][j]);
                count++;
            }
            rowEnd--;

            for(int i=rowEnd;i>=rowSt && count<total;i--){
                ans.push_back(matrix[i][colSt]);
                count++;
            }
            colSt++;
        }
        return ans;
    }
};