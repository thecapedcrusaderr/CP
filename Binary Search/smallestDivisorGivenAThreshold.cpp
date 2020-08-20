class Solution {
public:

    int support(vector<int> &nums, int divisor)
    {
        int ans = 0;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            ans += ceil(nums[i]/float(divisor));
        }
        return ans;
    }

    int smallestDivisor(vector<int>& nums, int threshold)
    {
        int low = 1;
        int high = *max_element(nums.begin(),nums.end());

        int ans = -1;
        while(low <= high)
        {
            int mid = (low+high)/2;
            int k = support(nums, mid);
            if(k <= threshold)
            {
                ans = mid ;
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }
        return ans;
    }
};
