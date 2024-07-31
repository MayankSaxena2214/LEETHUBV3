class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>ans;
        vector<int>shash(26,0);
        vector<int>phash(26,0);
        if(s.length()<p.length())return{};
        for(int i=0;i<p.length();i++){
            shash[s[i]-'a']++;
            phash[p[i]-'a']++;
        }
        if(phash==shash)ans.push_back(0);
        for(int i=p.length();i<s.length();i++){
            shash[s[i]-'a']++;
            shash[s[i-p.length()]-'a']--;
            if(shash==phash){
                ans.push_back(i-p.length()+1);
            }
        }
        return ans;
    }
};