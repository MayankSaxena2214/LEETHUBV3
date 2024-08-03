class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>a,vector<vector<int>>b){
        vector<vector<int>>v={{0,0},{0,0}};
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                for(int k=0;k<2;k++){
                    v[i][j]+=a[i][k]*b[k][j];
                }
            }
        }
        return v;
    }
    vector<vector<int>> fnc(vector<vector<int>>&a,int n){
        
        if(n==1)return a;
        vector<vector<int>>temp=fnc(a,n/2);
        if(n%2==0){
            return multiply(temp,temp);
        }
        else{
            return multiply(temp,multiply(temp,a));
        }
    }
    int fib(int n) {
        if(n==0)return 0;
        vector<vector<int>>a={{1,1},{1,0}};
        vector<vector<int>>ans=fnc(a,n);
        return ans[0][1];
    }
};