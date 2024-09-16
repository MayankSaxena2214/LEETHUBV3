class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>shash(26,0);
        vector<int>phash(26,0);
        if(p.length()>s.length())return {};
        for(int i=0;i<p.length();i++){
            phash[p[i]-'a']++;
            shash[s[i]-'a']++;
        }
        vector<int>ans;
        int n=p.length();
        if(phash==shash)ans.push_back(0);
        for(int i=n;i<s.length();i++){
            //removal
            shash[s[i-n]-'a']--;
            //addition
            shash[s[i]-'a']++;
            if(phash==shash)ans.push_back(i-n+1);

        }
        return ans;
    }
};