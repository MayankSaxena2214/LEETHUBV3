class Solution {
public:
    static bool custom(string a,string b){
        if(a+b>b+a)return true;
        return false;
    }
    string largestNumber(vector<int>& nums) {
        vector<string>temp;
        for(auto val:nums){
            temp.push_back(to_string(val));
        }
        string ans;
        sort(temp.begin(),temp.end(),custom);
        for(auto str:temp){
            ans+=str;
        }
        int i=0;
        while(ans[i]=='0'){
            i++;
        }
        if(i>=ans.size()){
            return "0";
        }
        
        return ans.substr(i);
    }
};