//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    int signum(int a,int b){
        if(a==b)return 0;
        else if(a>b)return 1;
        else return -1;
    }
    double median=0;
    priority_queue<int,vector<int>,greater<int>>mini;
    priority_queue<int>maxi;
    //Function to insert heap.
    void insertHeap(int &x)
    {
        balanceHeaps(maxi,mini,x,median);
        
    }
    
    //Function to balance heaps.
    void balanceHeaps(priority_queue<int>&maxi,priority_queue<int,vector<int>,greater<int>>&mini,int x,double&median)
    {
        switch(signum(maxi.size(),mini.size())){
            case 0:
            if(x>median){
                mini.push(x);
                median=mini.top();
                
            }
            else{
                maxi.push(x);
                median=maxi.top();
            }
            break;
            case 1:
            if(x>median){
                mini.push(x);
                median=(maxi.top()+mini.top())/2.0;
            }
            else{
                mini.push(maxi.top());
                maxi.pop();
                maxi.push(x);
                median=(maxi.top()+mini.top())/2.0;
            }
            break;
            case -1:
            if(x<median){
                maxi.push(x);
                median=(maxi.top()+mini.top())/2.0;
            }
            else{
                maxi.push(mini.top());
                mini.pop();
                mini.push(x);
                median=(maxi.top()+mini.top())/2.0;
            }
        }
    }
    
    //Function to return Median.
    double getMedian()
    {
        return median;
        
    }
};


//{ Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}
// } Driver Code Ends