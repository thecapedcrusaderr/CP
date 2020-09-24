#include<bits/stdc++.h>
using namespace std;

int visitedAll;
int dp[1<<12][12];

int tsp(vector<vector<int>> &graph, int mask , int currVer)
{
    if(mask == visitedAll)
    {
      return graph[currVer][0];
    }
    if(dp[mask][currVer]!=-1)return dp[mask][currVer];

    int ans = INT_MAX;

    for(int city = 0 ; city < graph.size(); city++)
    {
        if(mask & (1<<city) == 0)
        {
            int here = graph[currVer][city] + tsp(graph, mask | (1<<city), city);
            ans = min(ans, here);
        }
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;

    vector<vector<int>> graph(n, vector<int> (n));

    for(int i = 0 ; i < n ;i++)
    {
      for(int j = 0 ; j < n ; j++)
      {
        cin>>graph[i][j];
      }
    }

    for(int i = 0 ; i < 1<<12 ; i++)
    {
      for(int j = 0 ; j < 12 ; j++)
      {
        dp[i][j] = -1;
      }
    }

    visitedAll = 1<<n;
    cout<<tsp(graph, 0, 0);
}
