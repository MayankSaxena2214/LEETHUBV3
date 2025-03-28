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
            chars[ansIndex++]=ch;
            int count=j-i;
            if(count>1){
                string cnt=to_string(count);
                for(auto chr:cnt){
                    chars[ansIndex++]=chr;
                }
            }
            i=j;
        }
        return ansIndex;
    }
};