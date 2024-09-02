class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start=0,end=0;
        set<char>st;
        int ans=0;
        while(end<s.length()){
            if(st.find(s[end])==st.end()){
                st.insert(s[end]);
                ans=max(ans,end-start+1);
                end++;
            }
            else{
                st.erase(s[start]);
                start++;
            }
        }
        return ans;
    }
};