class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start=0,end=0;
        unordered_set<char>st;
        int n=s.length();
        int ans=0;
        while(end<n){
            if(st.find(s[end])==st.end()){
                ans=max(ans,end-start+1);
                st.insert(s[end]);
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