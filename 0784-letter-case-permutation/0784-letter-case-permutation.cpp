class Solution {
public:
    void solve(string str,auto&ans,auto temp,int index){
        if(index>=str.length()){
            ans.push_back(temp);
            return ;
        }
        if(str[index]>='0' && str[index]<='9'){
            solve(str,ans,temp+str[index],index+1);
        }
        else{
            solve(str,ans,temp+(char)tolower(str[index]),index+1);
            solve(str,ans,temp+(char)toupper(str[index]),index+1);
            
        }
    }
    vector<string> letterCasePermutation(string s) {
        vector<string>ans;
        string temp="";
        int index=0;
        solve(s,ans,temp,index);
        return ans;
    }
};