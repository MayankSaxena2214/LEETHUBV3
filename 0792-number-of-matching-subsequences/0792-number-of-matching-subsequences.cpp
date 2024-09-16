class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        map<char,vector<int>>mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]].push_back(i);
        }
        int count=0;
        for(auto word:words){
            int latest=-1;
            for(int j=0;j<word.length();j++){
                auto it=upper_bound(mp[word[j]].begin(),mp[word[j]].end(),latest);
                if(it==mp[word[j]].end()){
                    break;
                }
                latest=*it;
                if(j==word.length()-1){
                    count++;
                }
            }
        }
        return count;
    }
};