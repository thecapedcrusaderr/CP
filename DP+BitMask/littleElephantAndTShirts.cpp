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
      getchar(); // Ye ensure krta hai ki agla input next line pa aaye

      vector<vector<int>> graph(101);
      for(int i = 0 ;i < n ;i++)
      {
          string input;
          getline(cin,input);
          istringstream next(input);
          int num;
          while(next>>num)graph[num].push_back(i);
      }

      int visitedAll = (1<<n) - 1;
      vector<int> dp( 1<<n, 0);
      dp[0] = 1;

      for(int id = 1 ; id <= 100 ; id++)
      {
          for(int mask = visitedAll; mask >= 0 ; mask--)
          {
              for(auto nex : graph[id])
              {
                  if((mask & (1<<nex))==0)continue;
                  dp[mask] += dp[mask ^ (1<<nex)];
              }
          }
      }
      cout<<" answer is "<<dp[visitedAll]<<endl;
   }
}
