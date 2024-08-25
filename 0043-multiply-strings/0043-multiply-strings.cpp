class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0")return "0";
        int n=num1.size();
        int m=num2.size();
        vector<int>num(n+m,0);
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int val=num[i+j+1]+(num1[i]-'0')*(num2[j]-'0');
                num[i+j+1]=val%10;
                num[i+j]+=val/10;
            }
        }
        string result;
        for(int i=0;i<num.size();i++){
            result+=to_string(num[i]);
        }
        cout<<result<<endl;
        //leading zero removal
        int i;
        for( i=0;i<result.size() && result[i]=='0';i++){

        }
        return result.substr(i);      
    }
};