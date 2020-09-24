// Although i finally know it's nlog(n) solution, i have to understand intuition behind it.
class Solution {
public:

    int binarySearch(vector<int> &last, int num)
    {
        int n = last.size();
        int ans = -1;

        int low = 0, high = n-1;
        while(low <= high)
        {
            int mid = low + (high-low)/2;
            if(last[mid] >= num)
            {
                ans = mid;
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }
        return ans;
    }

    int lengthOfLIS(vector<int>& nums)
    {
        int n = nums.size();

        vector<int> last;

        for(auto &num : nums)
        {
            int ind = binarySearch(last, num);
            // cout<<" ind is "<<ind<<" for num = "<<num<<endl;
            if(ind==-1)
            {
                last.push_back(num);
            }
            else
            {
                last[ind] = num;
            }
        }
        return last.size();
    }
};
