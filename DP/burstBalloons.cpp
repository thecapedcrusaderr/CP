#include<bits/stdc++.h>
using namespace std;

int maxCoins(vector<int>& nums)
{
    int n = nums.size();
    nums.push_back(1);
    nums.insert(nums.begin(),1);

    vector<vector<int>> dp(n+2, vector<int> (n+2,0));

    for(int len = 1 ; len <= n ; len++)
    {
      for(int start = 1; start <= n - len + 1 ; start++)
      {
        int end = start + len - 1;
        int ans = 0;

        for(int k = start ; k <= end ; k++)
        {
           ans = max(ans, dp[start][k-1] + dp[k+1][end] + nums[k] * nums[end+1] * nums[start-1]);
        }
        dp[start][end] = ans;
      }
    }
  return dp[1][n];
}
