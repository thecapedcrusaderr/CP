// samajh gya!!
// Mtlb jo nodes isse discover hore, wo child ke liye consider hoga, agar root hai to 2 child ho wrna koi aisa child ho jo isse discover
// ho and uska low iske disc se >= ho to ye articulation point hai.
#include<bits/stdc++.h>
using namespace std;
const int N = 10005;
vector<int> g[N];


int vis[N], disc[N], low[N];

void init()
{
    for(int i = 0 ; i < N ; i++)
    {
      vis[i] = 0;
      disc[i] = 0;
      low[i] = 0;
      g[i].clear();
    }
}

void dfs(int curr, int parent, int &tm, int &count)
{
    vis[curr] = true;
    disc[curr] = tm;
    low[curr] = tm;
    int child = 0;
    bool hua = false;
    for(auto &nex : g[curr])
    {
        if(parent==nex)continue;
        if(!vis[nex])
        {
            tm++;
            dfs(nex, curr, tm, count);
            low[curr] = min(low[curr], low[nex]);
            if(disc[curr] <= low[nex])hua = true;
            child++;
        }
        else
        {
            low[curr] = min(low[curr], disc[nex]);
        }
    }

    if(curr == 0)
    {
        if(child > 1){ count++;}
    }
    else
    {
        if(hua){count++;}
    }
}

int main()
{
    while(1)
    {
        int n , m;
        cin>>n>>m;
        if(n==0 && m==0)break;
        init();
        for(int i = 0 ; i < m ; i++)
        {
            int a, b;
            cin>>a>>b;
            g[a-1].push_back(b-1);
            g[b-1].push_back(a-1);
        }
        int tm = 1, count = 0;
        dfs(0, -1, tm, count);
        cout<<count<<endl;
    }
    return 0;
}
