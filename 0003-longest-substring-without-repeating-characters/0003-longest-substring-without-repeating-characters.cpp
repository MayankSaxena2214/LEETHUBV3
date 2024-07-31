class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start=0,end=0;
        int ans=0;
        set<char>st;
        while(start<s.length()){
            char ch=s[start];
            if(st.find(ch)==st.end()){
                st.insert(ch);
                start++;
                ans=max(ans,start-end);
            }
            else{
                //remove the character pointed by e
                char rem=s[end];
                st.erase(rem);
                end++;
            }
        }
        return ans;
    }
};