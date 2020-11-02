#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;
vector<int> height;

void dfs(vector<int> &xorValue, vector<vector<int>> &graph, vector<int> &arr, vector<bool> &visited, int curr, int val)
{
    xorValue[curr] = val ^ arr[curr];
    visited[curr] = true;

    for(auto &nex : graph[curr])
    {
        if(!visited[nex])
        {
            dfs(xorValue, graph, arr, visited, nex, xorValue[curr]);
        }
    }
}

void dfsDPTable(int curr, int parent, int level, vector<vector<int>> &graph)
{
    int k = dp[curr].size();
    height[curr] = level;
    dp[curr][0] = parent;

    for(int i = 1 ; i < k ; i++)
    {
        dp[curr][i] = dp[dp[curr][i-1]][i-1];
    }

    for(auto &nex : graph[curr])
    {
        if(nex!=parent)
        {
            dfsDPTable(nex, curr, level+1, graph);
        }
    }

}

int findLCA(int u, int v, int k)
{
  if (height[u] < height[v])
      swap(u, v);

  for (int i = k-1; i >= 0; i--)
      if ((height[u] - (1<<i)) >= height[v])
          u = dp[u][i];

  if (u == v)
      return u;

  for (int i = k-1; i >= 0; i--)
  {
      if (dp[u][i] != dp[v][i])
      {
          u = dp[u][i];
          v = dp[v][i];
      }
  }

  return dp[u][0];
}

int main()
{
    int n, q;
    cin>>n>>q;
    vector<int> arr(n);
    for(int i = 0 ; i < n ; i++)
    {
        cin>>arr[i];
    }

    vector<vector<int>> graph(n);
    vector<int> parent(n,-1);

    for(int i = 0 ; i < n-1 ; i++)
    {
        int u, v;
        cin>>u>>v;
        graph[u-1].push_back(v-1);
        graph[v-1].push_back(u-1);
    }
    vector<int> xorValue(n,0);
    vector<bool> visited(n, false);
    dfs(xorValue, graph, arr, visited, 0, 0);

    height.resize(n,0);
    int k = ceil(log2(n)) + 1;
    dp.resize(n, vector<int> (k,-1));
    dfsDPTable(0,0,0,graph);

    // All i have to do is to find LCA of two numbers now.

    while(q--)
    {
        int first , second;
        cin>>first>>second;
        int lca = findLCA(first-1, second-1, k);
        int temp = xorValue[first] ^ xorValue[second] ^ arr[lca];
        if(temp==0)
        {
            cout<<"Alex"<<endl;
        }
        else
        {
            cout<<"Bob"<<endl;
        }
    }
    return 0;
}
