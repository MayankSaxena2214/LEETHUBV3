class Solution {
public:
char toLower(char ch){
    if(ch>='a' && ch<='z'){
        return ch;
    }
    else {
        char ret=ch-'A'+'a';
        return ret;
    }
}
char toUpper(char ch){
    if(ch>='a' && ch<='z'){
        char ret=ch-'a'+'A';
        return ret;
    }
    else {
        return ch;
    }
}
    void solve(string str,auto&ans,string path,int index,int n){
        if(index==n){
            ans.push_back(path);
            return;
        }
        if(str[index]>='0' && str[index]<='9'){
            solve(str,ans,path+str[index],index+1,n);
        }
        else{
            //lowercase call
            solve(str,ans,path+toLower(str[index]),index+1,n);
            //uppercase call
            solve(str,ans,path+toUpper(str[index]),index+1,n);
        }
    }
    vector<string> letterCasePermutation(string s) {
        vector<string>ans;
        string path;
        int index=0;
        int n=s.length();
        solve(s,ans,path,index,n);
        return ans;
    }
};