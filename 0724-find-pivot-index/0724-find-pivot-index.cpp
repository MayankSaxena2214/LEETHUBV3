class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        vector<int>sumLeft,sumRight(n);
        int sum=0;
        for(auto val:nums){
            sum+=val;
            sumLeft.push_back(sum);
        }
        sum=0;
        for(int i=n-1;i>=0;i--){
            sum+=nums[i];
            sumRight[i]=sum;
        }
        for(int i=0;i<n;i++){
            if(sumLeft[i]==sumRight[i]){
                return i;
            }
        }
        return -1;

    }
};