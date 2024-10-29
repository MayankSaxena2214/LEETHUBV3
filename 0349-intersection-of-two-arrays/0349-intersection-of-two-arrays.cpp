class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int i=0,j=0;
        vector<int>ans;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int n1=nums1.size();
        int n2=nums2.size();
        while(i<n1 && j<n2){
            if(nums1[i]==nums2[j]){
                int val=nums1[i];
                ans.push_back(val);
                while(i<n1 && nums1[i]==val){
                    i++;
                }
                while(j<n2 && nums2[j]==val)j++;
            }
            else if(nums1[i]>nums2[j]){
                j++;
            }
            else{
                i++;
            }
        }
        return ans;
    }
};