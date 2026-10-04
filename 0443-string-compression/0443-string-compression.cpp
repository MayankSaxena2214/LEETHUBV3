class Solution {
public:
    int compress(vector<char>& chars) {
        int i=0;
        int n=chars.size();
        int ansIndex=0;
        while(i<n){
            int curr=chars[i];
            int j=i+1;
            while(j<n && chars[j]==curr){
                j++;
            }
            int count=j-i;
            chars[ansIndex++]=curr;
            if(count>1){
                string cnt=to_string(count);
                for(auto ch:cnt){
                    chars[ansIndex++]=ch;
                }
                i=j;
            }
            else{
                i++;
            }
            
        }
        return ansIndex;
    }
};