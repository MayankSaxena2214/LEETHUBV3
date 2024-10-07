class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string temp;
        vector<string>hold;
        while(ss>>temp){
            hold.push_back(temp);
        }
        string ans;
        for(int i=hold.size()-1;i>=0;i--){
            ans+=hold[i];
            ans+=' ';
        }
        if(hold.size()==0){
            return ans;
        }
        ans.pop_back();
        return ans;
    }
};