class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(s.length()<k)return false;
        unordered_set<string>st;
        for(int i=0;i<s.length()-k+1;i++){
            st.insert(s.substr(i,k));
        }
        return st.size()==pow(2,k);
    }
};