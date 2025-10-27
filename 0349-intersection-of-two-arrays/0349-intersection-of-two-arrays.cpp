class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int n=nums1.size();
        int m=nums2.size();
        vector<int>ans;
        int i=0,j=0;
        while(i<n && j<m){
            int val1=nums1[i];
            int val2=nums2[j];

            if(val1==val2){
                ans.push_back(val1);

                //skip all
                while(i<n && nums1[i]==val1){
                    i++;
                }
                while(j<m && nums2[j]==val2){
                    j++;
                }
                
            }
            else if(val1<val2){
                i++;
            }
            else{
                j++;
            }
        }
        return ans;
    }
};