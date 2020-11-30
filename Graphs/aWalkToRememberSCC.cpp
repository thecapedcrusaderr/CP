#include<bits/stdc++.h>
using namespace std;
int u, v, l;


int revDfs(vector<vector<int>> &revGraph, vector<int> &out, vector<bool> &revVis, int curr)
{
    revVis[curr] = true;
    out[curr] = 1;
    int temp = 0;
    for(auto &nex : revGraph[curr])
    {
        if(!revVis[nex])
        {
            temp++;
            l = revDfs(revGraph, out, revVis, nex);
        }
    }
    return temp;
}

void dfs(vector<vector<int>> &graph, vector<bool> &vis, stack<int> &s, int curr)
{
    vis[curr] = true;
    for(auto &nex : graph[curr])
    {
        if(!vis[nex])dfs(graph, vis, s, nex);
    }
    s.push(curr);
}

int main()
{
    int n, m;
    cin>>n>>m;
    vector<vector<int>> graph(n), revGraph(n);
    vector<bool> vis(n, false), revVis(n, false);
    vector<int> out(n, 0);
    stack<int> s;
    for(int i =0 ; i< m ; i++)
    {
        cin>>u>>v;
        graph[u-1].push_back(v-1);
        revGraph[v-1].push_back(u-1);
    }

    for(int i = 0 ; i < n ; i++)
    {
        if(!vis[i])dfs(graph, vis, s, i);
    }

    while(s.size())
    {
        int upar = s.top();
        s.pop();
        if(revVis[upar])continue;
        int temp = revDfs(revGraph, out, revVis, upar);
        if(temp==0)out[upar] = 0;
    }

    for(int i = 0 ; i < n ; i++)
    {
        cout<<out[i]<<" ";
    }
    cout<<endl;
    return 0;
}
