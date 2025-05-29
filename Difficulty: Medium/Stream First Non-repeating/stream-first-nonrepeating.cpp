class Solution {
  public:
    string FirstNonRepeating(string &s) {
        // Code here
        unordered_map<char,int>mp;
        queue<char>q;
        string ans;
        for(auto ch:s){
            mp[ch]++;
            q.push(ch);
            //now check
            while(!q.empty() && mp[q.front()]>1){
                q.pop();
            }
            if(q.empty()){
                ans.push_back('#');
            }
            else{
                ans.push_back(q.front());
            }
        }
        return ans;
        
    }
};