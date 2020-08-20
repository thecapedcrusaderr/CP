#include<bits/stdc++.h>
#define m 1000000007
using namespace std;


int countPalindromicSubsequences(string S)
{
    int n = S.size();
    vector<vector<int>> dp(n, vector<int> (n,0));

    for(int i = 0 ; i < n ;i++)
    {
      dp[i][i] = 1;
    }

    for(int len = 1; len < n; len++)
    {
      for(int i = 0; i < n - len ; i++)
      {
        int j = i+len;
        if(S[i]==S[j])
        {
          int low = i+1;
          int high = j-1;

          while(low <= high && S[low]!=S[i])low++;
          while(low <= high && S[high]!=S[i])high--;

          if(low > high)
          {
            dp[i][j] = dp[i+1][j-1] * 2 + 2;
          }
          else if(low == high)
          {
            dp[i][j] = dp[i+1][j-1] * 2 + 1;
          }
          else
          {
            dp[i][j] = dp[i+1][j-1] * 2 - dp[low+1][high-1];
          }
        }
        else
        {
          dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1];
        }
        dp[i][j] = dp[i][j] > 0 ? dp[i][j] % m : dp[i][j] + m;
      }
    }
    return dp[0][n-1];
}
