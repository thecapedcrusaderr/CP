#include<bits/stdc++.h>
using namespace std;

int maxEnvelopes(vector<vector<int>>& envelopes)
{
  int n = envelopes.size();
  sort(envelopes.begin(),envelopes.end());

  vector<int> dp(n,1);
  int ans = 1;

  for(int i = n-2 ; i >= 0 ; i--)
  {
    for(int j = i+1; j<=n-1; j++)
    {
      if(envelopes[i][0] < envelopes[j][0] && envelopes[i][1] < envelopes[j][1])
      {
          dp[i] = max(dp[i], dp[j]+1);
      }
    }
    ans = max(ans, dp[i]);
  }
  return ans;
}
