class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>count1(26,0);
        vector<int>count2(26,0);
        for(auto ch:s){
            count1[ch-'a']++;
        }
        for(auto ch:t){
            count2[ch-'a']++;
        }
        return count1==count2;
    }
};