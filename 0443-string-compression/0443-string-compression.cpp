class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        int i=0;
        int ansIndex=0;
        while(i<n){
            char ch=chars[i];
            int j=i;
            while(j<n && chars[j]==ch){
                j++;
            }
            int count=j-i;
            chars[ansIndex++]=ch;
            if(count>1){
                string cnt=to_string(count);
                for(auto ch:cnt){
                    chars[ansIndex++]=ch;
                }
            }
            i=j;
        }
        return ansIndex;
    }
};