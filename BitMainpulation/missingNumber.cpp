// This bit manipulation solution was freaking crazy. Hope i am getting along with it.

class Solution {
public:
    int missingNumber(vector<int>& nums)
    {
        int n = nums.size();
        int ans = n;
        for(int i = 0 ; i < n ; i++)
        {
            ans ^= (i^nums[i]);
        }
        return ans;
    }
};
