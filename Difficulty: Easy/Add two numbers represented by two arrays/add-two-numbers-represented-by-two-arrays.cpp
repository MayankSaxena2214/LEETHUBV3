//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    string calc_Sum(int *a,int n,int *b,int m){
    // Complete the function
    string ans="";
        int carry=0;
        int i=n-1,j=m-1;
        while(i>=0 && j>=0){
            int total=a[i]+b[j]+carry;
            int sum=total%10;
            carry=total/10;
            ans.push_back(sum-0 +'0');
            i--;
            j--;
        }
        while(i>=0){
            int total=a[i]+carry;
            int sum=total%10;
            carry=total/10;
            ans.push_back(sum-0 +'0');
            i--;
        }
        while(j>=0){
            int total=b[j]+carry;
            int sum=total%10;
            carry=total/10;
            ans.push_back(sum-0 +'0');
            j--;
        }
        // while(carry!=0){
        //     int total=carry;
        //     int sum=total%10;
        //     carry=total/10;
        //     ans+=to_string(sum);
        // }
        if(carry)ans.push_back(carry-0 +'0');
        while(ans.back()=='0')ans.pop_back();
        reverse(ans.begin(),ans.end());
        // if(ans[0]=='0'){
        //     int i=0;
        //     while(ans[i]=='0'){
        //         i++;
        //         return ans.substr(i);
        //     }
        // }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
	    int m;
	    cin>>m;
	    int b[m];
	    for(int i=0;i<m;i++){
	        cin>>b[i];
	    }
	    Solution ob;
	    cout << ob.calc_Sum(a,n,b,m) << endl;
	}
	return 0;
}
// } Driver Code Ends