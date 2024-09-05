class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int>st;
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            if(ch=='('){
                st.push(i);
            }
            else if(ch==')'){
                if(!st.empty() && s[st.top()]=='('){
                    st.pop();
                }
                else{
                    st.push(i);
                }
            }
        }
        while(!st.empty()){
            int index=st.top();
            st.pop();
            s.erase(index,1);
        }
        return s;
    }
};