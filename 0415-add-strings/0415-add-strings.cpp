class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans;
        int carry=0;
        int n=num1.length(),m=num2.length();
        int i=n-1,j=m-1;
        while(i>=0 && j>=0){
            int val1=num1[i]-'0';
            int val2=num2[j]-'0';
            int total=val1+val2+carry;
            carry=total/10;
            int digit=total%10;
            ans.push_back(digit+'0');
            i--;
            j--;
        }
        while(i>=0){
            int val1=num1[i]-'0';
            int total=val1+carry;
            carry=total/10;
            int digit=total%10;
            ans.push_back(digit+'0');
            i--;
        }
        while(j>=0){
            int val2=num2[j]-'0';
            int total=val2+carry;
            carry=total/10;
            int digit=total%10;
            ans.push_back(digit+'0');
            j--;
        }
        while(carry!=0){
            int total=carry;
            carry=total/10;
            int digit=total%10;
            ans.push_back(digit+'0');
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};