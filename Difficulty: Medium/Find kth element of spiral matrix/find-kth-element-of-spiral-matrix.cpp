//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
class Solution
{
    public:
    /*You are required to complete this method*/
    int findK(int matrix[MAX][MAX],int r,int c,int k)
    {
 		// Your code goes here.int rowst=0,rowend=r-1,colst=0,colend=c-1;
 		 int rowst=0,rowend=r-1,colst=0,colend=c-1;
        int total=r*c;
        int count=0;
        while(count<total){
            for(int col=colst;col<=colend&& count < total;col++){
                count++;
                if(count==k)return matrix[rowst][col];
            }
            rowst++;
            for(int row=rowst;row<=rowend&& count < total;row++){
                count++;
                if(count==k)return matrix[row][colend];
            }
            colend--;
            for(int col=colend;col>=colst&& count < total;col--){
                count++;
                if(count==k)return matrix[rowend][col];
            }
            rowend--;
            for(int row=rowend;row>=rowst&& count < total;row--){
                count++;
                if(count==k)return matrix[row][colst];
            }
            colst++;
        }
        return -1;
    }
};





//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        cout<<ob.findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends