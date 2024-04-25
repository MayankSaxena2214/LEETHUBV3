class Solution {
public:
    vector<string>mapping={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void solve(string digits,int index,auto&ans,auto&output){
        if(index>=digits.length()){
            ans.push_back(output);
            return;
        }
        int idx=digits[index]-'0';
        string value=mapping[idx];
        for(int i=0;i<value.length();i++){
            output.push_back(value[i]);
            solve(digits,index+1,ans,output);
            output.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        
        int index=0;
        vector<string>ans;
        if(digits.length()==0)return ans;
        string output;
        solve(digits,index,ans,output);
        return ans;
    }
};