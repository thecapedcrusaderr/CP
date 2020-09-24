// Tagda question dp + BitMask ka

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dp, graph;

void solve()
{
    int n, m;
    cin>>n>>m;

    graph.resize(n, vector<int> (n, 1000));

    // Since the maximum value of graph could be 100, we have assigned 1000 here

    for(int i=0; i<m; ++i)
    {
        int u, v, w;
        cin>>u>>v>>w;
        graph[u-1][v-1] = min(w, graph[u-1][v-1]);
        graph[v-1][u-1] = min(w, graph[u-1][v-1]);
    }

    dp.resize((1<<n), vector<int> (n,10000));

    for(int i=0; i<n; ++i)
    {
        dp[1<<i][i] = 0;
    }

    for(int mask = 0 ; mask < (1<<n); mask++)
    {
        for(int u = 0 ; u < n ; u++)
        {
            if((mask & (1<<u))==0)continue;

            for(int v = 0 ; v < n ; v++)
            {
                if((mask & (1<<v))==0)continue;

                int temp = mask ^ (1<<v);
                dp[mask][v] = min(dp[mask][v], dp[temp][u]+graph[u][v]);
            }
        }
    }

    int ans = 10000;
    for(int i=0; i<n; ++i)
        ans = min(ans, dp[(1<<n)-1][i]);
    cout<<ans<<endl;
}

int main()
{
    solve();
    return 0;
}
