class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>v(26,0);
        for(auto ch:s){
            v[ch-'a']++;

        }
        for(auto ch:t){
            v[ch-'a']--;
        }
        for(auto val:v){
            if(val!=0)return false;
        }
        return true;

    }
};