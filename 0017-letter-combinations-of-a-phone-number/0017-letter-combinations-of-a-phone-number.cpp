class Solution {
public:
    unordered_map<int,string>mp={{2,"abc"},{3,"def"},{4,"ghi"},{5,"jkl"},{6,"mno"},{7,"pqrs"},{8,"tuv"},{9,"wxyz"}};
    void solve(string &digits,auto&ans,auto&temp,int index){
        if(index>=digits.length()){
            ans.push_back(temp);
            return;
        }
        int mpindex=digits[index]-'0';
        string curr=mp[mpindex];
        for(int i=0;i<curr.length();i++){
            temp.push_back(curr[i]);
            solve(digits,ans,temp,index+1);
            temp.pop_back();
        }
        

    }
    vector<string> letterCombinations(string digits) {
        int index=0;
        if(digits.length()==0)return {};
        vector<string>ans;
        string temp;
        solve(digits,ans,temp,index);
        return ans;
    }
};