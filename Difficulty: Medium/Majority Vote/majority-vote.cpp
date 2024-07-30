//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> Solve(int n, vector<int>& nums) {
        // Code here
        int candidate1=INT_MIN,candidate2=INT_MIN;
        int count1=0,count2=0;
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(candidate1==nums[i])count1++;
            else if(candidate2==nums[i])count2++;
            else if(count1==0){
                candidate1=nums[i];
                count1=1;
            }
            else if(count2==0){
                candidate2=nums[i];
                count2=1;
            }
            else{
                count1--;
                count2--;
            }
        }
        int freq1=0,freq2=0;
        for(auto val:nums){
            if(val==candidate1)freq1++;
            if(val==candidate2)freq2++;
        }
        if(freq1>n/3)ans.push_back(candidate1);
        if(freq2>n/3)ans.push_back(candidate2);
        if(ans.size()==0)return {-1};
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        Solution obj;

        vector<int> res = obj.Solve(n, a);

        for (auto x : res) cout << x << " ";

        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends