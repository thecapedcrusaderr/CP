// One of the nicest question i came across

class Solution {
public:
    int find(vector<int> &parent, int num)
    {
        while(parent[num]!=num)
        {
            num = parent[num];
        }
        return num;
    }

    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges)
    {
        int n = edges.size();
        vector<int> parent(n+1,0), cand1, cand2;

        for(auto &e : edges)
        {
            int a = e[0], b = e[1];
            if(parent[b]==0)parent[b] = a;
            else
            {
                cand1 = {parent[b],b};
                cand2 = e;
                e[1] = 0;
            }
        }

        for(int i = 1 ; i<= n ;i++)parent[i] = i;
        for(auto &e : edges)
        {
            if(e[1]==0)continue;
            int u = e[0], v = e[1], pu = find(parent,u);
            if(pu==v)
            {
                if(cand1.empty()) return e;
                return cand1;
            }
            parent[v] = pu;
        }
        return cand2;
    }
};
