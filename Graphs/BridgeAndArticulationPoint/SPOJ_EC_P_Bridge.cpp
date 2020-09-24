#include <bits/stdc++.h>
using namespace std;


void dfs(vector<bool> &vis, vector<int> &disc, vector<int> &low, vector<vector<int>> &ans, vector<vector<int>> &graph, int curr, int parent, int &tm)
{
    vis[curr] = true;
    disc[curr] = tm;
    low[curr] = tm;

    for(auto &nex : graph[curr])
    {
        if(nex==parent)continue;

        if(!vis[nex])
        {
            tm++;
            dfs(vis, disc, low, ans, graph, nex, curr, tm);
            if(low[nex] > disc[curr])
            {
                ans.push_back({min(curr,nex), max(curr,nex)});
            }
            low[curr] = min(low[curr],low[nex]);
        }
        else
        {
           if(parent!=nex)
           {
             low[curr] = min(low[curr], disc[nex]);
           }
        }
    }
}


int main()
{
	int t;
    cin>>t;

    for(int i = 0 ; i < t ; i++)
    {
      int n, m;
      cin>>n>>m;

      vector<vector<int>> graph(n+1, vector<int> ());

      for(int j = 0 ; j < m ; j++)
      {
          int a , b;
          cin>>a>>b;
          graph[a].push_back(b);
          graph[b].push_back(a);
      }

      vector<bool> vis(n+1,false);
      vector<int> disc(n+1,-1);
      vector<int> low(n+1,-1);
      vector<vector<int>> ans;

      int tm = 1;
      dfs(vis, disc, low, ans, graph, 1, -1, tm);
      sort(ans.begin(),ans.end());

      int sz = ans.size();

      cout<<"Caso #"<<i+1<<endl;
      if(sz==0)
      {
        cout<<"Sin bloqueos"<<endl;
      }
      else
      {
          cout<<sz<<endl;
          for(int j = 0 ; j < ans.size(); j++)
          {
              cout<<ans[j][0]<<" "<<ans[j][1]<<endl;
          }
      }
    }

	return 0;
}
