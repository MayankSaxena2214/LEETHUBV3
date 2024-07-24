class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int>temp=nums;
        for(int i=0;i<temp.size();i++){
            nums[(i+k)%temp.size()]=temp[i];
        }
    }
};