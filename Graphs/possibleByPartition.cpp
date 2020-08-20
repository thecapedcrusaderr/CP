bool possibleBipartition(int N, vector<vector<int>>& dislikes)
{
    vector<int> dp(N+1,-1);
    int size = dislikes.size();
    unordered_map<int,vector<int>> edges;

    vector<int> colors(N+1,-1);

    for(int i = 0 ; i < size ; i++)
    {
        edges[dislikes[i][0]].push_back(dislikes[i][1]);
        edges[dislikes[i][1]].push_back(dislikes[i][0]);
    }

    for(int i = 1; i <= N ;i++)
    {
        if(colors[i]==-1  && !applydfs(i,0,colors,edges))return false;
    }
    return true;
  }

bool applydfs(int node, int color, vector<int> &colors, unordered_map<int, vector<int>>& edges)
{
    if(colors[node]!=-1)
    {
        return colors[node]==color;
    }

    colors[node] = color;

    for(auto neb : edges[node])
    {
        if(!applydfs(neb, color^1 , colors, edges))return false;
    }
    return true;
}
