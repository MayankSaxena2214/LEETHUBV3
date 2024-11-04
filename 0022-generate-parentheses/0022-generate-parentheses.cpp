class Solution {
public:
    void solve(auto&ans,auto temp,int open,int close,int n){
        if(open==n && close==n){
            ans.push_back(temp);
            return ;
        }
        if(open<n){
            temp.push_back('(');
            solve(ans,temp,open+1,close,n);
            temp.pop_back();
        }
        if(close<open){
            temp.push_back(')');
            solve(ans,temp,open,close+1,n);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        int open=0;
        int close=0;
        string temp;
        vector<string>ans;
        solve(ans,temp,open,close,n);
        return ans;
    }
};