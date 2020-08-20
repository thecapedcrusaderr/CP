class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K)
    {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        vector<int> dist(n,INT_MAX);
        dist[src] = 0;
        ++K;
        while(K--)
        {
            vector<int> temp(dist);
            for(int i = 0 ; i < flights.size() ; i++)
            {
                int s = flights[i][0], d = flights[i][1], dis = flights[i][2];
                if(dist[s]!=INT_MAX){temp[d] = min(temp[d],dist[s]+dis);}
            }
            dist = temp;
        }
        return dist[dst]==INT_MAX ? -1 : dist[dst];

    }
};
