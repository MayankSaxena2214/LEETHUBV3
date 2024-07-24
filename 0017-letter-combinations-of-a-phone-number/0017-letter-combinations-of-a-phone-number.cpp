class Solution {
public:
    void solve(string&digits,vector<string>&ans,string output,auto&mp,int index){
        if(index>=digits.length()){
            ans.push_back(output);
            return;
        }
        char digit=digits[index];
        string mapped=mp[digit-'0'+0];
        for(int i=0;i<mapped.length();i++){
            output.push_back(mapped[i]);
            solve(digits,ans,output,mp,index+1);
            output.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<int,string>mp={{2,"abc"},{3,"def"},{4,"ghi"},{5,"jkl"},{6,"mno"},{7,"pqrs"},{8,"tuv"},{9,"wxyz"}};
        vector<string> ans;
        if(digits.length()==0)return ans;
        string output;
        int index=0;
        solve(digits,ans,output,mp,index);
        return ans;
    }
};