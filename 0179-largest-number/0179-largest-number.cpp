class Solution {
public:
    static bool cmp(string a,string b){
        if(a+b > b+a)return true;
        return false;
    }
    string largestNumber(vector<int>& nums) {
        vector<string>arr;
        for(auto val:nums){
            arr.push_back(to_string(val));
        }
        sort(arr.begin(),arr.end(),cmp);
        string ans;
        for(auto str:arr){
            ans+=str;
        }
        //now remove the starting zeroers i.e. 0000
        if(ans[0]=='0')return "0";
        return ans;      
    }
};