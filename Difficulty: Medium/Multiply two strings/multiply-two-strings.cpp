//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
class Solution{
  public:
    /*You are required to complete below function */
    string multiplyStrings(string s1, string s2) {
       //Your code here
       bool neg1=(s1[0]=='-')?true:false;
       bool neg2=(s2[0]=='-')?true:false;
       if(s1[0]=='-'){
           s1=s1.substr(1);
       }
       if(s2[0]=='-'){
           s2=s2.substr(1);
       }
       bool final=false;
       if((neg1==true && neg2==false) || (neg1==false && neg2==true)){
           final=true;
       }
       int n=s1.length();
       int m=s2.length();
       vector<int>num(n+m,0);
       string result;
       if(s1=="0" || s2=="0")return "0";
       for(int i=n-1;i>=0;i--){
           for(int j=m-1;j>=0;j--){
               int val=num[i+j+1]+(s1[i]-'0')*(s2[j]-'0');
               num[i+j+1]=val%10;
               num[i+j]+=val/10;
           }
       }
    //   cout<<"final sigin is "<<final<<endl;
       
       for(auto val:num){
           result+=to_string(val);
       }
       //leading zeroes
       int i;
       for(i=0;i<result.length() && result[i]=='0';i++){};
       result=result.substr(i);
    //   cout<<result<<endl;
        if(result.length()==0)return "0";
       string finalans=(final==true)?'-'+result:result;
       return finalans;
    }

};

//{ Driver Code Starts.
 
int main() {
     
    int t;
    cin>>t;
    while(t--)
    {
    	string a;
    	string b;
    	cin>>a>>b;
    	Solution obj;
    	cout<<obj.multiplyStrings(a,b)<<endl;
    }
     
}
// } Driver Code Ends