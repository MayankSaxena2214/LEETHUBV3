class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int i=0,j=0;
        vector<int>ans;
        int size1=nums1.size(),size2=nums2.size();
        while(i<size1 && j<size2){
            if(nums1[i]==nums2[j]){
                ans.push_back(nums1[i]);
                int curr=nums1[i];
                while(i<size1 && nums1[i]==curr){
                    i++;
                }
                while(j<size2 && nums2[j]==curr){
                    j++;
                }
            }
            else if(nums1[i]<nums2[j]){
                i++;
            }
            else{
                j++;
            }
        }
        return ans;
    }
};