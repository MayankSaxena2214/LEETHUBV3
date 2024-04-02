class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char,int>mp;
        int count=0;
        for(auto ch:allowed)mp[ch]++;
        for(auto str:words){
            bool flag=true;
            for(auto ch:str){
                if(mp.find(ch)==mp.end()){
                    flag=false;
                }
            }
            if(flag)count++;
        }
        return count;
    }
};