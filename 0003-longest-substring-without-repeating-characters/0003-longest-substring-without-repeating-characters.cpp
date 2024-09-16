class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start=0,end=0;
        int ans=0;
        int n=s.length();
        unordered_set<char>st;
        while(end<n){
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