class Solution {
public:

    int support(vector<int> &bloomDay, int mid, int m , int k)
    {
        int total = 0, cnt = 0;
        for(int i = 0 ; i < bloomDay.size(); i++)
        {
            if(bloomDay[i] <= mid)
            {
                cnt++;
                if(cnt == k)
                {
                    total++;
                    cnt = 0;
                }
            }
            else
            {
                cnt = 0;
            }
        }
        return total;
    }

    int minDays(vector<int>& bloomDay, int m, int k)
    {
        int ans = -1;
        int n = bloomDay.size();
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        while(low <= high)
        {
            int mid = (low + high)/2;
            int data = support(bloomDay, mid, m , k);
            if(data >= m)
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
};
