class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        int rowst=0,colst=0;
        int rowend=rows-1,colend=cols-1;
        int total=rows*cols;
        int count=0;
        vector<int>ans;
        while(count<total){
            for(int j=colst;j<=colend && count<total;j++){
                ans.push_back(matrix[rowst][j]);
                count++;
            }
            rowst++;
            for(int j=rowst;j<=rowend && count<total;j++){
                ans.push_back(matrix[j][colend]);
                count++;
            }
            colend--;
            for(int j=colend;j>=colst && count<total;j--){
                ans.push_back(matrix[rowend][j]);
                count++;
            }
            rowend--;
            for(int i=rowend;i>=rowst && count<total;i--){
                ans.push_back(matrix[i][colst]);
                count++;
            }
            colst++;
        }
        return ans;
    }
};