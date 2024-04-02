class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        vector<string>temp;
        string buff;
        while(ss>>buff){
            temp.push_back(buff);
        }
        for(int i=0;i<temp.size();i++){
            reverse(temp[i].begin(),temp[i].end());
        }
        // for(int i=0;i<temp.size();i++){
        //     if(i+1<temp.size()){
        //         swap(temp[i],temp[i+1]);
        //     }
        // }
        string ans;
        for(int i=0;i<temp.size();i++){
            if(i!=temp.size()-1){
                ans+=temp[i];
                ans+=' ';
            }
            else{
                ans+=temp[i];
            }
        }
        return ans;
    }
};