class Solution {
public:

    void graph(vector<vector<pair<int,int>>> &edges, vector<bool> &visited, vector<int> &dist,int src)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        visited[src] = true;
        int next = -1;

        for(auto p : edges[src])
        {
            int a = p.first, b = p.second;
            if(visited[a])continue;
            dist[a] = min(dist[a],dist[src]+b);
        }

        int N = dist.size() , minm = INT_MAX, neb = -1;
        for(int i = 1 ; i <= N-1 ; i++)
        {
            if(visited[i])continue;
            if(dist[i] < minm)
            {
                minm = dist[i];
                neb = i;
            }
        }
        if(minm==INT_MAX)return;
        graph(edges,visited,dist,neb);
    }

    int networkDelayTime(vector<vector<int>>& times, int N, int K)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
       vector<int> dist(N+1,INT_MAX);

        vector<vector<pair<int,int>>> edges(N+1);

        for(int i = 0 ; i < times.size(); i++)
        {
            int from = times[i][0], to = times[i][1], weight = times[i][2];
            edges[from].push_back({to,weight});
        }

        vector<bool> visited(N+1,false);
        dist[K] = 0;
        graph(edges,visited,dist,K);

        int ans = -1;
        for(int i = 1 ; i <= N ; i++)
        {
            if(dist[i]==INT_MAX)return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};
