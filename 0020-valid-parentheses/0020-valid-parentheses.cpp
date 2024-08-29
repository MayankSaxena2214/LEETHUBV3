class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(auto ch:s){
            if(ch=='(' ||ch=='{' ||ch=='['){
                st.push(ch);
            }
            else{
                if(st.empty()){
                    return false;
                }
                else{
                    char top=st.top();
                    st.pop();
                    if((top=='(' && ch==')')|| (top=='{' && ch=='}') || (top=='[' && ch==']')){
                        
                    }
                    else{
                        return false;
                    }
                }
            }
        }
        if(st.empty())return true;
        return false;
    }
};