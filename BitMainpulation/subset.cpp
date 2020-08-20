// thoda bohut bit manipulation samajh me aa rha hai
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums)
    {
        int n = nums.size();
        int p = 1<<n;
        vector<vector<int>> out(p);
        for(int i = 0 ; i < p ; i++)
        {
            for(int j = 0 ; j < n; j++)
            {
                if(1 & i>>j)
                {
                    out[i].push_back(nums[j]);
                }
            }
        }
        return out;
    }
};
