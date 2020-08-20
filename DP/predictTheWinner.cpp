#include<bits/stdc++.h>
using namespace std;

bool PredictTheWinner(vector<int>& nums)
{
  int n = nums.size();
  vector<vector<int>> dp(n, vector<int> (n,0));
  vector<int> prefixSum(n);

  prefixSum[0] = nums[0];
  dp[0][0] = nums[0];
  for(int i = 1; i < n ;i++)
  {
    prefixSum[i] = prefixSum[i-1] + nums[i];
    dp[i][i] = nums[i];
  }

  for(int len = 1; len < n ;len++)
  {
    for(int i = 0 ; i < n-len; i++)
    {
      int j = i + len;
      int diff = 0;
      if(i==0)
      {
        dp[i][j] = max(nums[i]+prefixSum[j]-prefixSum[i]-dp[i+1][j], prefixSum[j-1]-dp[i][j-1]+nums[j]);
      }
      else
      {
        dp[i][j] =  max(nums[i]+prefixSum[j]-prefixSum[i]-dp[i+1][j], prefixSum[j-1]-prefixSum[i-1]-dp[i][j-1]+nums[j]);
      }
    }
  }

  if(dp[0][n-1] >= ceil(prefixSum[n-1]/2.0))return true;
  else return false;
}
