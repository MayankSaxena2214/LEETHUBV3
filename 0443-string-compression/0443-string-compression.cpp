class Solution {
public:
    int compress(vector<char>& chars) {
        int ansindex=0;
        int i=0;
        int n=chars.size();
        while(i<chars.size()){
            char element=chars[i];
            int j=i+1;
            while(j<n && chars[j]==element){
                j++;
            }
            chars[ansindex++]=chars[i];
            int count=j-i;
            if(count>1){
                string cnt=to_string(count);
                for(auto ch:cnt){
                    chars[ansindex++]=ch;
                }
            }
            i=j;
        }
        return ansindex;
    }
};