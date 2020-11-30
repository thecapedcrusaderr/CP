#include<bits/stdc++.h>
using namespace std;
void countSCC(int curr, vector<vector<int>> &rg,  vector<bool> &newVisit)
{
    newVisit[curr] = true;
    for(auto &nex : rg[curr])
    {
        if(!newVisit[nex])
        {
            countSCC(nex, rg,  newVisit);
        }
    }
}

void dfs(int curr, stack<int> &s, vector<bool> &visited,   vector<int> adj[])
{
    visited[curr] = true;
    for(auto &nex : adj[curr])
    {
        if(!visited[nex])
        {
            dfs(nex, s, visited,  adj);
        }
    }
    s.push(curr);
}

int kosaraju(int V, vector<int> adj[])
{
    stack<int> s;
    vector<vector<int>> rg(V);
    for(int i = 0 ; i < V ; i++)
    {
        for(auto &nex : adj[i])
        {
            rg[nex].push_back(i);
        }
    }
    vector<bool> visited(V, false);
    for(int i = 0 ; i < V ; i++)
    {
        if(!visited[i])
        {
            dfs(i, s, visited,   adj);
        }
    }

    vector<bool> newVisit(V, false);
    int count = 0;

    while(s.size())
    {
        int yahan = s.top();
        s.pop();
        if(!newVisit[yahan])
        {
            count++;
            countSCC(yahan, rg, newVisit);
        }
    }
    return count;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
      int a, b;
      cin>>a>>b;
      int m, n;
      vector<int> adj[a];
      for(int i =0 ; i < b ; i++)
      {
        cin>>m>>n;
        adj[m].push_back(n);
      }
      cout<<kosaraju(a, adj)<<endl;
    }
    return 0;
}
