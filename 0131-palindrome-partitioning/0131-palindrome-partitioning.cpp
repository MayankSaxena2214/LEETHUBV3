class Solution {
public:
    bool isPalindrome(string s){
        string temp=s;
        reverse(temp.begin(),temp.end());
        return s==temp;
    }
    void solve(string s,auto&ans,auto&v){
        if(s.length()==0){
            cout<<"reached"<<endl;
            ans.push_back(v);
            return;
        }
        for(int i=1;i<=s.length();i++){
            string first=s.substr(0,i);
            string second=s.substr(i);
            if(isPalindrome(first)){
                v.push_back(first);
                solve(second,ans,v);
                v.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>v;
        solve(s,ans,v);
        return ans;
    }
};