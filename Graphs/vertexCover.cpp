// This question was asked in test of harness, in 2019.
#include<bits/stdc++.h>
using namespace std;

pair<int,int> dfs(vector<vector<int>> &graph, vector<bool> &visited, int curr)
{
    visited[curr] = true;
    int a = 0, b = 0;

    for(auto &nex : graph[curr])
    {
        if(!visited[nex])
        {
            pair<int,int> here = dfs(graph, visited, nex);
            a+=min(here.first, here.second);
            b+=here.first;
        }
    }
    a+=1;
    return {a,b};
}

int hospital(int city_nodes, vector<int> &city_from , vector<int> &city_to)
{
    if(city_nodes==1)return 1;
    vector<vector<int>> graph(city_nodes);
    int n = city_from.size();
    for(int i = 0 ; i < n ;i++)
    {
        graph[city_from[i]-1].push_back(city_to[i]-1);
        graph[city_to[i]-1].push_back(city_from[i]-1);
    }
    vector<bool> visited(city_nodes,false);
    pair<int,int> now = dfs(graph, visited,0);
    return min(now.first, now.second);
}
