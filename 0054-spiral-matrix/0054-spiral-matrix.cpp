class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        int rowst=0,rowend=rows-1;
        int colst=0,colend=cols-1;
        int count=0;
        int total=rows*cols;
        vector<int>ans;
        while(count<total){
            for(int col=colst;col<=colend && count<total;col++){
                ans.push_back(matrix[rowst][col]);
                count++;
            }
            rowst++;
            for(int row=rowst;row<=rowend && count<total;row++){
                ans.push_back(matrix[row][colend]);
                count++;
            }
            colend--;
            for(int col=colend;col>=colst && count<total;col--){
                ans.push_back(matrix[rowend][col]);
                count++;
            }
            rowend--;
            for(int row=rowend;row>=rowst && count<total;row--){
                ans.push_back(matrix[row][colst]);
                count++;
            }
            colst++;
        }
        return ans;
    }
};