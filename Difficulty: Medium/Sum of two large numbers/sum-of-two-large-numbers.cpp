//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    string findSum(string num1, string num2) {
        // Your code goes here
        int n=num1.length();
    int m=num2.length();
    int i=n-1,j=m-1;
    int carry=0;
    string ans;
    while(i>=0 && j>=0){
        int val1=num1[i]-'0'+0;
        int val2=num2[j]-'0'+0;
        int total=val1+val2+carry;
        int digit=total%10;
        carry=total/10;
        ans.push_back(digit-0+'0');
        i--;
        j--;
    }
    while(i>=0){
        int val1=num1[i]-'0'+0;
        
        int total=val1+carry;
        int digit=total%10;
        carry=total/10;
        ans.push_back(digit-0+'0');
        i--;
      
    }
    while(j>=0){
        
        int val2=num2[j]-'0'+0;
        int total=val2+carry;
        int digit=total%10;
        carry=total/10;
        ans.push_back(digit-0+'0');
        j--;
    }
    while(carry!=0){
        int total=carry;
        int digit=total%10;
        carry=total/10;
        ans.push_back(digit+'0');
    }
    reverse(ans.begin(),ans.end());
    int count=0;
    while(ans[count]=='0' ){
        count++;
    }
    string final=ans.substr(count);
    if(final.length()==0)return "0";
    else return final;
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string x, y;
        cin >> x >> y;
        Solution ob;
        cout << ob.findSum(x, y) << "\n";
    }

    return 0;
}
// } Driver Code Ends