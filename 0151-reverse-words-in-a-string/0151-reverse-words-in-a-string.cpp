class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string buff;
        vector<string>temp;
        while(ss>>buff){
            temp.push_back(buff);
        }
        string ans;
        int n=temp.size();
        for(int i=n-1;i>=0;i--){
            if(i==0){
                ans+=temp[i];
            }
            else{
                ans+=temp[i];
                ans+=' ';
            }
        }
        return ans;
    }
};