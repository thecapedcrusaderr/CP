#include<bits/stdc++.h>
using namespace std;

int cnt;

void dfs(int u, vector<vector<int>> &g, vector<int> &visited)
{
    visited[u] = 1;
    cnt++;
    for(auto &v : g[u])
    {
        if(!visited[v])dfs(v, g, visited);

        if(visited[v]==1)cnt--;
    }
    visited[u] = 2;
}

int tasks(int n, vector<int> &a, vector<int> &b)
{
    vector<vector<int>> g(n);
    int u,v, m = a.size();
    for(int i = 0 ; i < m ; i++)
    {
        u = a[i]-1;
        v = b[i]-1;
        g[v].emplace_back(u);
    }
    vector<int> visited(n);
    int ans = 0;

    for(int i = 0 ; i < n ; i++)
    {
        if(!visited[i])
        {
          cnt = 0;
          dfs(i, g, visited);
          ans += cnt;
        }
    }
    return ans;
}

// Basically ye topological sort wala logic lgaya hai.
