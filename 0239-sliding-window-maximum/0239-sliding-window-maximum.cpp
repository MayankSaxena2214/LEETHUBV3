class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int>ans;
        int n =nums.size();
        for(int i=0;i<k;i++){
            while(!dq.empty() && nums[dq.back()]<nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);

        }
        ans.push_back(nums[dq.front()]);
        for(int i=k;i<n;i++){
            //removal logic
            while(!dq.empty()&&i-dq.front()>=k){
                dq.pop_front();
            }
            //addition logic
            while(!dq.empty() && nums[dq.back()]<=nums[i]){
                dq.pop_back();

            }
            dq.push_back(i);
            ans.push_back(nums[dq.front()]);

        }
        return ans;
    }
};