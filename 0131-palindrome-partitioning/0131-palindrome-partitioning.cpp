class Solution {
public:
    bool isPalindrome(string str){
        string temp=str;
        reverse(temp.begin(),temp.end());
        return temp==str;
    }
    void solve(vector<vector<string>>&ans,vector<string>temp,string s){
        if(s.length()<1){
            ans.push_back(temp);
            return;
        }
        for(int len=1;len<=s.length();len++){
            string first=s.substr(0,len);
            if(isPalindrome(first)){
                temp.push_back(first);
                solve(ans,temp,s.substr(len,s.length()-len));
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>temp;
        solve(ans,temp,s);
        return ans;
    }
};