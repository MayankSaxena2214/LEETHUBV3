class Solution {
public:
    unordered_map<int,string>mp={{2,"abc"},{3,"def"},{4,"ghi"},{5,"jkl"},{6,"mno"},{7,"pqrs"},{8,"tuv"},{9,"wxyz"}};
    void solve(vector<string>&ans,string temp,string digits,int index){
        if(index>=digits.length()){
            ans.push_back(temp);
            return;
        }
        int digit=digits[index]-'0';
        string value=mp[digit];
        for(int i=0;i<value.length();i++){
            temp.push_back(value[i]);
            solve(ans,temp,digits,index+1);
            temp.pop_back();
        }

    }
    vector<string> letterCombinations(string digits) {
        int index=0;
        if(digits.length()==0)return {};
        
        vector<string>ans;
        string temp;
        solve(ans,temp,digits,index);
        return ans;
    }
};