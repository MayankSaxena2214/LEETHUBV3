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
            for(int i=colst;i<=colend && count<total;i++){
                ans.push_back(matrix[rowst][i]);
                count++;
            }
            rowst++;
            for(int i=rowst;i<=rowend && count<total;i++){
                ans.push_back(matrix[i][colend]);
                count++;
            }
            colend--;
            for(int i=colend;i>=colst && count<total;i--){
                ans.push_back(matrix[rowend][i]);
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