int minCut(string s)
{
int n = s.size();
vector<vector<bool>> dp(n,vector<bool> (n,false));
for(int i = 0 ; i < n ; i++)
{
dp[i][i] = true;
}

for(int j = 1 ; j < n ; j++)
{
for(int i = j-1 ; i>=0 ;i--)
{
  if(s[j]==s[i])
  {
    if(j-i == 1)
    {
      dp[i][j] = true;
    }
    else
    {
      dp[i][j] = dp[i+1][j-1];
    }
  }
  else
  {
    dp[i][j] = false;
  }
}
}

vector<int> finalDP(n+1);
finalDP[0] = -1;
finalDP[1] = 0;

for(int j = 1 ; j < n ; j++)
{
int ans = INT_MAX;
for(int i = j; i >= 0; i--)
{
  if(s[i]==s[j])
  {
    if(i==j)
    {
        ans = min(ans , s1+finalDP[i]);
    }
    else if(j-i == 1)
    {
        ans = min(ans,1+finalDP[i]);
    }
    else
    {
        if(dp[i+1][j-1])
        {
          ans = min(ans,1+finalDP[i]);
        }
        else
        {
          ans = min(ans, finalDP[i] + j-i+1);
        }
    }
  }
  else
  {
    ans = min(ans, finalDP[i] +j-i+1);
  }
}
finalDP[j+1] = ans;
}

return finalDP[n];
}
