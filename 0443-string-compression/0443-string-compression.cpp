class Solution {
public:
    int compress(vector<char>& chars) {
        int ansIndex=0;
        int i=0;
        int n=chars.size();
        while(i<n){
            char ch=chars[i];
            int j=i+1;
            while(j<n && chars[j]==ch){
                j++;
            }
            chars[ansIndex++]=ch;
            int count=j-i;
            if(count>1){
                string cnt=to_string(count);
                for(auto val:cnt){
                    chars[ansIndex++]=val;
                }
            }
            i=j;
        }
        return ansIndex;
    }
};