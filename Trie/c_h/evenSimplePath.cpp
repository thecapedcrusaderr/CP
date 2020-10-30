#include<bits/stdc++.h>
using namespace std;

void dfs(vector<pair<int,int>> &g, vector<bool> &visited, vector<int> &height, vector<int> &value, int curr, int h, int val)
{
    visited[curr] = true;
    value[curr] = val;
    height[here] = h;
    for(auto &nex : g[curr])
    {
        int a = nex.first, b = nex.second;
        if(!visited[a])
        {
            dfs(g, visited, height, value, a, h+1, val^b);
        }
    }
}

int main()
{
    int n, q;
    cin>>n>>q;

    vector<pair<int,int>> g(n);
    for(int i = 0 ; i < n-1 ; i++)
    {
        int u, v, w;
        cin>>u>>v>>w;
        g[u-1].push_back({v-1,w});
        g[v-1].push_back({u-1,w});
    }
    vector<bool> visited(n, false);
    vector<int> height(n,0), value(n,0);
    dfs(g, visited, height, value, 0, 0, 0);

    while(q--)
    {
        int left, right;
        cin>>left>>right;
        if(value[left-1]!=value[right-1])
        {
          cout<<"NO"<<endl;
        }
        else
        {
          if((height[left-1]+height[right-1])%2 == 0)
          {
            cout<<"YES"<<endl;
          }
          else
          {
            cout<<"NO"<<endl;
          }
        }
    }
    return 0;
}
