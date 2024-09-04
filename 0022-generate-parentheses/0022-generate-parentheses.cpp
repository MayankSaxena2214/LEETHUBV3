class Solution {
public:
    void solve(auto&ans,string str,int open,int close,int n){
        if(open==n && close==n){
            ans.push_back(str);
            return;
        }
        if(open<n){
            str.push_back('(');
            solve(ans,str,open+1,close,n);
            str.pop_back();
        }
        if(close<open){
            str.push_back(')');
            solve(ans,str,open,close+1,n);
            str.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        int open=0,close=0;
        vector<string>ans;
        string str;
        solve(ans,str,open,close,n);
        return ans;
    }
};