class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int>ans;
        //first window process
        for(int i=0;i<k;i++){
            while(!dq.empty() && nums[dq.back()]<=nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        ans.push_back(nums[dq.front()]);
        for(int i=k;i<nums.size();i++){
            //removal logic
            while(!dq.empty() && i-dq.front()>=k){
                dq.pop_front();
            }
            //addition logic
            while(!dq.empty() && nums[dq.back()]<=nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            //maintain answer 
            ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};