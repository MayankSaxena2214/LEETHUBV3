class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int i=0,j=0;
        set<int>st;
        int size1=nums1.size(),size2=nums2.size();
        while(i<size1 && j<size2){
            if(nums1[i]==nums2[j]){
                st.insert(nums1[i]);
                i++;
                j++;
            }
            else if(nums1[i]<nums2[j]){
                i++;
            }
            else{
                j++;
            }
        }
        //put element in vector
        vector<int>ans;
        for(auto val:st){
            ans.push_back(val);
        }
        return ans;
        
    }
};