class Solution {
public:
unordered_map<int,string>mp={{2,"abc"},{3,"def"},{4,"ghi"},{5,"jkl"},{6,"mno"},{7,"pqrs"},{8,"tuv"},{9,"wxyz"}};

    void solve(string &digits,auto&ans,string temp,int index){
        if(index==digits.size()){
            ans.push_back(temp);
            return ;
        }
        int idx=digits[index]-'0';
        string word=mp[idx];
        for(int i=0;i<word.length();i++){
            temp.push_back(word[i]);
            solve(digits,ans,temp,index+1);
            temp.pop_back();
        }

    }
    vector<string> letterCombinations(string digits) {
                if(digits.length()==0)return {};
        vector<string>ans;
        string temp;
        solve(digits,ans,temp,0);
        return ans;
    }
};