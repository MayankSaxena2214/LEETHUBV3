//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    //You need to complete this fucntion
       const int m=1e9+7;
    long long myPow(int x,int n){
        if(n==0)return 1;
        long long temp=myPow(x,n/2);
        if(n%2==0)
        {
            return  (temp*temp)%m;
        }
        else{
            return (((temp*temp)%m)*x)%m;
        }
    }
    long long power(int N,int R)
    {
       //Your code here
       return myPow(N,R);
        
    }

};

//{ Driver Code Starts.

// compute reverse of a number 
long long rev(long long n)
{
    long long rev_num = 0;
     while(n > 0) 
      { 
        rev_num = rev_num*10 + n%10; 
        n = n/10; 
      } 
      return rev_num;
}




int main()
{
    int T;
    cin>>T;//testcases
    
    while(T--)
    {
        long long N;
        cin>>N;//input N
        
        long long R = 0; 
        
        // reverse the given number n
        R = rev(N);
        Solution ob;
        //power of the number to it's reverse
        long long ans =ob.power(N,R);
        cout << ans<<endl;
    }
}
// } Driver Code Ends