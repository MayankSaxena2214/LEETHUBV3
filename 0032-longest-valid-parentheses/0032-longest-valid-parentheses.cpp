class Solution {
public:
    int longestValidParentheses(string s) {
        int ans=0;
        int left=0,right=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            char ch=s[i];
            if(ch=='(')left++;
            else right++;
            if(right==left)ans=max(ans,left*2);
            if(right>left)left=right=0;
        }
        left=0,right=0;
        for(int i=n-1;i>=0;i--){
            char ch=s[i];
            if(ch=='(')left++;
            else right++;
            if(left==right)ans=max(ans,left*2);
            if(right<left)left=right=0;
        }
        return ans;

    }
};