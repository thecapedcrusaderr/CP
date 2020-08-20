class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        vector<vector<pair<int,int>>> graph(N+1);
        for(int i = 0 ; i < times.size(); i++)
        {
            int from = times[i][0], to = times[i][1], wght = times[i][2];
            graph[from].push_back({to,wght});
        }

        vector<int> dist(N+1,INT_MAX);

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        pq.push({0,K});
        dist[K] = 0;
        int ans = -1;

        while(pq.size())
        {
            int pr = pq.top().second;
            int from = pq.top().first;
            // cout<<"the number being popped with its distance is "<<pr<<" "<<from<<endl;
            pq.pop();

            for(auto p : graph[pr])
            {
                int a = p.first, b = p.second;
                if(dist[a] > from + b)
                {
                    dist[a] = from + b;
                    pq.push({dist[a],a});
                }
            }
        }
        for(int i = 1 ; i <= N ; i++)
        {
            // cout<<"dist["<<i<<"] is "<<dist[i]<<endl;
            ans = max(ans, dist[i]);
        }
        return ans==INT_MAX ? -1 : ans;

    }
};
