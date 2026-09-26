class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        vector<int>ans;
        int i=0,j=0;
        int l1=nums1.size();
        int l2=nums2.size();

        while(i<l1 && j<l2){
            int val1=nums1[i];
            int val2=nums2[j];
            if(val1<val2){
                i++;
            }
            else if(val1>val2){
                j++;
            }
            else{
                ans.push_back(val1);
                //equal case
                while( i<l1 && nums1[i]==val1 )i++;
                while(j<l2 && nums2[j]==val2 )j++;
                
            }
        }
        return ans;
    }
};