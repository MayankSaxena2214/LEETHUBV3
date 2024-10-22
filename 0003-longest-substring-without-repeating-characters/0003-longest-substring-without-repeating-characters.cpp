class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start=0,e=0;
        int n=s.length();
        int ans=0;
        unordered_set<char>st;
        while(e<n){
            auto it=st.find(s[e]);
            if(it==st.end()){
                st.insert(s[e]);
                ans=max(ans,e-start+1);
                e++;
            }
            else{
                st.erase(s[start]);
                start++;
            }
        }
        return ans;
    }
};