class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        vector<unordered_set<int>> graph(n);
        for(auto &e : edges)
        {
            int a = e[0], b = e[1];
            graph[a].insert(b);
            graph[b].insert(a);
        }

        if(n==1) return {0};
        vector<int> curr;
        for(int i = 0 ; i < n ; i++)
        {
            if(graph[i].size()==1)
            {curr.push_back(i);}
        }

        while(true)
        {
            vector<int> next;

            for(auto &num : curr)
            {
                for(auto &k : graph[num])
                {
                    graph[k].erase(num);
                    if(graph[k].size()==1)
                    {
                        next.push_back(k);
                    }
                }
            }
            if(next.size()==0)return curr;
            curr = next;
        }
        return {};
    }
};
