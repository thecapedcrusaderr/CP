// First time i am gonna implement MST with the help of Union Find(Disjoint Set). It would be a good learning opportunity.

// I have applied union find with path compression and rank compression.

class Solution {
public:

    static bool keseKrnaHai(vector<int> &a, vector<int> &b)
    {
        return a[2] < b[2];
    }

    void merge(vector<int> &parent, vector<int> &rank, int a, int b)
    {
        int p1 = findParent(parent, a );
        int p2 = findParent(parent, b);
        if(rank[p1] >= rank[p2])
        {
            parent[p2] = p1;
            rank[p1] += rank[p2];
        }
        else
        {
            parent[p1] = p2;
            rank[p2] += rank[p1];
        }
    }

    int findParent(vector<int> &parent, int p)
    {
        if(parent[p]==p)return p;
        int pf = findParent(parent, parent[p]);
        parent[p] = pf;
        return pf;
    }

    int findMst(int n , vector<vector<int>> &edges, int toIgnore, int toInclude)
    {
        vector<int> parent(n,-1);
        for(int i = 0 ; i < n ; i++)parent[i] = i;

        vector<int> rank(n, 1);
        int ans = 0;

        if(toInclude != -1)
        {
            ans += edges[toInclude][2];
            merge(parent, rank ,edges[toInclude][0], edges[toInclude][1]);
        }

        for(int i = 0 ; i < edges.size(); i++)
        {
            if(toIgnore == i)continue;
            if(toInclude == i)continue;
            int a = edges[i][0], b = edges[i][1];
            int pa = findParent(parent, a);
            int pb = findParent(parent, b);

            if(pa!=pb)
            {
                ans += edges[i][2];
                merge(parent, rank, pa, pb);
            }
        }
        for(int i = 0 ; i < edges.size(); i++)
        {
            if(findParent(parent, edges[i][0]) != findParent(parent, edges[i][1]))
            {
                return INT_MAX;
            }
        }

        return ans;
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges)
    {
        vector<int> critical, pseudoCritical;

        int m = edges.size();
        for(int i = 0 ; i < m ; i++)
        {
            edges[i].push_back(i);
        }

        sort(edges.begin(),edges.end(), keseKrnaHai);

        int valMinSpnTree = findMst(n, edges, -1, -1);

        for(int i = 0 ; i < edges.size(); i++)
        {
            int here = findMst(n, edges, i, -1);
            if(here > valMinSpnTree)
            {
                critical.push_back(edges[i][3]);
            }
            else
            {
                if(here == findMst(n, edges, i, i))pseudoCritical.push_back(edges[i][3]);
            }

        }
        return {critical , pseudoCritical};
    }
};
