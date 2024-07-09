//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void solve(vector<vector<int> >&ans,vector<int>temp,int index,vector<int>a){
        if(index==a.size()){
            ans.push_back(temp);
            return;
        }
        solve(ans,temp,index+1,a);
        temp.push_back(a[index]);
        index++;
        solve(ans,temp,index,a);
        
    }
    vector<vector<int> > subsets(vector<int>& a) {
        // code here
        vector<vector<int> >ans;
        if(a.size()==0)return ans;
        int index=0;
        vector<int>temp;
        solve(ans,temp,index,a);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, x;
        cin >> n;

        vector<int> array;
        for (int i = 0; i < n; i++) {
            cin >> x;
            array.push_back(x);
        }

        Solution ob;
        vector<vector<int> > res = ob.subsets(array);

        // Print result
        for (int i = 0; i < res.size(); i++) {
            for (int j = 0; j < res[i].size(); j++)
                cout << res[i][j] << " ";
            cout << endl;
        }
    }

    return 0;
}
// } Driver Code Ends