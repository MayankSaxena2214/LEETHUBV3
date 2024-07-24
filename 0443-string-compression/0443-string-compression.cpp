class Solution {
public:
    int compress(vector<char>& chars) {
        int ansIndex=0;
        int i=0;
        int n=chars.size();
        while(i<chars.size()){
            int curr=chars[i];
            int j=i+1;
            while(j<n && chars[j]==curr){
                j++;
            }
            chars[ansIndex++]=chars[i];
            int count=j-i;
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