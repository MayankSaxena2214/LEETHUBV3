class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<int> temp;
        for(auto i:nums1){
            temp.push_back(i);
        }
        for(auto i:nums2){
            temp.push_back(i);
        }
        sort(temp.begin(),temp.end());
        int mid=(n+m)/2;
        if((n+m)%2==0){
            
            int el1=temp[mid];
            int el2=temp[mid-1];
            return (el1+el2)/2.0;
        }
        else{
            return temp[mid]*1.0;
        }
        
    }
};