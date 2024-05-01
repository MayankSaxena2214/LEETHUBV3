class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        for(auto i:nums1)ans.push_back(i);
        for(auto i:nums2)ans.push_back(i);
        sort(ans.begin(),ans.end());
        int n=ans.size();
        if(n%2!=0){
            return ans[ans.size()/2]*1.0;
        }
        else{
            int val1=ans[n/2];
            int val2=ans[n/2-1];
            return ((val1+val2)/2.0);
        }
        
    }
};