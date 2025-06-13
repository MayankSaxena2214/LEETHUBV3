class Solution {
public:
void solve(auto&ans,auto temp,int index,string&digits,auto&mp){
    if(index>=digits.length()){
        ans.push_back(temp);
        return;
    }
    int digit=digits[index]-'0';
    string str=mp[digit];
    for(int i=0;i<str.length();i++){
        temp.push_back(str[i]);
        solve(ans,temp,index+1,digits,mp);
        temp.pop_back();
    }

}
    vector<string> letterCombinations(string digits) {
        unordered_map<int, string> mp =
        { {2, "abc"},
          {3, "def"},
          {4, "ghi"},
          {5, "jkl"},
          {6, "mno"},
          {7, "pqrs"},
          {8, "tuv"},
          {9, "wxyz"} };

        vector<string>
            ans;
            if(digits.length()==0)return {};
        string temp;
        int index = 0;
        solve(ans, temp, index, digits, mp);
        return ans;
    }
};