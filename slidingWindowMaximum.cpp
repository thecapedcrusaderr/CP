// Learnt a new concept here
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        deque<int> dq;
        vector<int> ans(nums.size()-k+1);
        for(int i = 0 ; i < nums.size(); i++)
        {
            if(!dq.empty() && i-dq.front()==k)
            {
                dq.pop_front();
            }
            while(!dq.empty() && nums[i] >= nums[dq.back()])
            {
                dq.pop_back();
            }
            dq.push_back(i);
            if(i-k+1 >= 0)
            ans[i-k+1] = nums[dq.front()];
        }
        return ans;
    }
};
