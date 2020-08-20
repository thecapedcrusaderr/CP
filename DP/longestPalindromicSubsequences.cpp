#include<bits/stdc++.h>
using namespace std;

int longestPalindromeSubseq(string s)
{
      int n = s.size();
      if(n==0)return 0;
       if(n==1)return 1;
      vector<vector<int>> dp(n,vector<int> (n,1));

      for(int i = 0 ; i < n-1; i++)
      {
        if(s[i]==s[i+1])
        {
          dp[i][i+1] = 2;
        }
      }
      for(int len = 2; len < n ;len++)
      {
        for(int i = 0; i < n-len ; i++)
        {
          int j = i+len;
          if(s[i]==s[j])
          {
              dp[i][j] = 2 + dp[i+1][j-1];
          }
          else
          {
              dp[i][j] = max(dp[i][j-1], dp[i+1][j]);
          }
        }
      }
      return dp[0][n-1];
}
