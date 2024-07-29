//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int rowWithMax1s(vector<vector<int> > &arr) {
        
        int prevMax=-1;
        int currMax=-1;
        int row=arr.size();
        int ansrow=-1;
        int col=arr[0].size();
        for(int i=0;i<row;i++){
            int count=0;
            for(int j=0;j<col;j++){
                if(arr[i][j]==1)count++;
            }
            if(count==0)continue;
            if(i==0){
                if(currMax<count){
                    prevMax=count;
                    currMax=count;
                    ansrow=i;
                }
            }
            else{
                if(currMax<count){
                    if(count==prevMax){
                        continue;
                    }
                    else{
                        if(count>prevMax){
                            currMax=count;
                            prevMax=count;
                            ansrow=i;
                        }
                    }
                }
            }
        }
        return ansrow;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > arr(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends