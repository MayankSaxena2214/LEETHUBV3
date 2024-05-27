void solve(string temp,vector<string>&ans,int N,int count){
    if(count==N){
        if(temp.length()==N){
            ans.push_back(temp);
        }
        
        return;
    }
    solve(temp+'0',ans,N,count+1);
    
    if(temp.back()!='1'){
        solve(temp+'1',ans,N,count+1);
        
    }
}
vector<string> generateString(int N) {
    // Write your code here.
    vector<string>ans;
    string temp;
    int count=0;
    solve(temp,ans,N,count);
    return ans;
}