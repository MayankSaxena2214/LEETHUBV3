class Solution {
public:
    string removeDuplicates(string s) {
        string ans;
        for(auto ch:s){
            if(ans.empty() || ans.back()!=ch){
                ans+=ch;
            }
            else{
                ans.pop_back();
            }
        }
        return ans;
    }
};