// Using union by rank or compressed union find. All possible optimisations of this.

class Solution {
public:

    bool join(vector<int> &parent, vector<int> &rank, int left, int right)
    {
        int leftPar = find(parent, left);
        int rightPar = find(parent, right);
        if(leftPar == rightPar)return true;
        if(rank[leftPar] >= rank[rightPar])
        {
            parent[rightPar] = parent[leftPar];
            rank[leftPar]++;
            return false;
        }
        else
        {
            parent[leftPar] = parent[rightPar];
            rank[rightPar]++;
            return false;
        }
    }

    int find(vector<int> &parent, int num)
    {
        while(parent[num]!=num)
        {
            num = parent[num];
        }
        return num;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges)
    {
        int n = edges.size();
        vector<int> parent(n+1);
        vector<int> rank(n+1,1);
        for(int i = 0 ; i <= n; i++)
        {
            parent[i] = i;
        }

        for(auto &e : edges)
        {
            int a = e[0], b = e[1];
            if(join(parent,rank,a,b))return {a,b};
        }
        return {};
    }
};
