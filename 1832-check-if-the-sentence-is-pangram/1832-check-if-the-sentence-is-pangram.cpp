class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int>v(26,0);
        for(auto ch:sentence){
            v[ch-'a']++;
        }
        for(auto val:v){
            if(val==0)return false;
        }
        return true;
    }
};