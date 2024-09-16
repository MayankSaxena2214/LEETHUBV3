class Solution {
public:
    string multiply(string num1, string num2) {
        int n=num1.length(),m=num2.length();
        if(num1=="0" || num2=="0")return "0";
        vector<int>nums(n+m,0);
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                nums[i+j+1]+=(num1[i]-'0')*(num2[j]-'0');
                nums[i+j]+=nums[i+j+1]/10;
                nums[i+j+1]%=10;
            }
        }
        string ans;
        for(int i=0;i<n+m;i++){
            ans+=nums[i]+'0';
        }
        int i=0;
        while(i<n+m && ans[i]=='0'){
            i++;
        }
        return ans.substr(i);


    }
};