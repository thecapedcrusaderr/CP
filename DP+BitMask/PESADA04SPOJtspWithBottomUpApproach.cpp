#include<bits/stdc++.h>
using namespace std;

int main()
{
      int t;
      cin>>t;

      while(t--)
      {
          int n;
          cin>>n;

          vector<vector<int>> graph(n+1, vector<int> (n+1, 0));
          for(int i = 0 ; i <= n ; i++)
          {
              for(int j = 0 ; j <= n ; j++)
              {
                if(i==j)continue;
                cin>>graph[i][j];
              }
          }

          int maxm = (1<<(n+1)) - 1;

          vector<vector<int>> dp(1<<(n+1), vector<int> (n+1, 200000));

          for(int i = 0 ; i <= n ; i++)
          {
              dp[1<<i][0] = 0;
          }
          // dp[maxm][0] = 0;

          for(int mask = 0 ; mask <= maxm ; mask++)
          {
              for(int startCity = 0 ; startCity <= n ; startCity++)
              {
                  if((mask & (1<<startCity))==0)continue;

                  for(int endCity = 1; endCity <= n ; endCity++)
                  {
                      if((startCity != endCity) && ((mask & (1<<endCity))!=0))
                      {
                          int temp = mask ^ (1<<endCity);
                          // cout<<" temp we got here is "<<temp<<endl;
                          dp[mask][endCity] = min(dp[mask][endCity], dp[temp][startCity] + graph[startCity][endCity]);
                          // cout<<" dp value for mask = "<<mask<<" and last city "<<endCity<<" with first city "<<startCity<<" is "<<dp[mask][endCity]<<endl;
                      }
                  }

              }
          }

          int ans = INT_MAX;
          for(int i = 1 ; i <= n ; i++)
          {
              ans = min(ans, dp[(1<<(n+1)) - 1][i] + graph[i][0]);
          }
          cout<<ans<<endl;
          return 0;
      }
}
