class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        vector<bool> visited(n,false);
        vector<vector<pair<int,double>>> graph(n);

        for(int i = 0 ; i < edges.size(); i++)
        {
            int a = edges[i][0];
            int b = edges[i][1];
            double c = succProb[i];
            graph[a].push_back({b,c});
            graph[b].push_back({a,c});
        }

        vector<double> dist(n,-1);
        dist[start] = 1;

        priority_queue<pair<double,int>> pq;
        pq.push({1,start});

        while(pq.size())
        {
            auto topEle = pq.top();
            pq.pop();
            double a = topEle.first;
            int b = topEle.second;
            if(visited[b])continue;
            visited[b] = true;

            for(auto &neb : graph[b])
            {
                int c = neb.first;
                double d = neb.second;
                if(visited[c])continue;

                if(dist[c] < dist[b] * d )
                {
                    dist[c] = dist[b] * d;
                    pq.push({dist[c],c});
                }

            }
        }

        return dist[end]==-1 ? 0 : dist[end];
    }
};
