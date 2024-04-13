class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<vector<int>>mat(m,vector<int>(n,0));
        for(auto v:indices){
            int row=v[0];
            int col=v[1];
            for(int i=0;i<n;i++){
                mat[row][i]++;
            }
            for(int i=0;i<m;i++){
                mat[i][col]++;
            }

        }
        int count=0;
        for(auto v:mat){
            for(auto val:v){
                if(val%2!=0)count++;
            }
        }
        return count;
    }
};