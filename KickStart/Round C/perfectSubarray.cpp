#include<bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  cin>>t;

  for(int i = 1; i <= t ; i++)
  {
    int n;
    cin>>n;
    vector<int> arr(n);

    int count = 0;

    for(int j = 0 ; j < n; j++)
    {
      cin>>arr[j];
    }

    vector<vector<int>> dp(n,vector<int> (n,0));

    for(int j = 0 ; j < n ;j++)
    {
      for(int k = j; k >= 0 ; k--)
      {
         if(k==j)
         {
            dp[k][j] = arr[j];
            int sq = round(sqrt(dp[k][j]));
            if(sq*sq == dp[k][j])
            {
              count++;
            }
         }
         else
         {
           dp[k][j] = dp[k+1][j]+arr[k];
           int sq = round(sqrt(dp[k][j]));
           if(sq*sq == dp[k][j])
           {
             count++;
           }
         }
      }
    }
    cout<<"Case #"<<i<<": "<<count<<endl;
  }

  return 0;
}
