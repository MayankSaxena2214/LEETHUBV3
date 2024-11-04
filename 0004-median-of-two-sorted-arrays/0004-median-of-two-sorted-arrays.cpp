class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int element1=0,element2=0;
        int i=0,j=0,k=0;
        int n=nums1.size(),m=nums2.size();
        int idx1=(n+m)/2;
        int idx2=idx1-1;
        while(i<n && j<m){
            if(nums1[i]<nums2[j]){
                if(k==idx1)element1=nums1[i];
            if(k==idx2)element2=nums1[i];
            i++;
            k++;
            }
            else{
                if(k==idx1)element1=nums2[j];
            if(k==idx2)element2=nums2[j];
            j++;
            k++;
            }
        }
        while(i<n){
            if(k==idx1)element1=nums1[i];
            if(k==idx2)element2=nums1[i];
            i++;
            k++;
        }
        while(j<m){
            if(k==idx1)element1=nums2[j];
            if(k==idx2)element2=nums2[j];
            j++;
            k++;
        }
        if((n+m)%2==0){
            return ((element1+element2)/2.0);
        }
        return element1;
    }
};