// Using Union Find algorithm to solve this problem

class Solution {
public:

    bool join(vector<int> &parents, int a, int b)
    {
        int left = find(parents,a);
        int right = find(parents,b);
        if(left==right)return true;
        else
        {
            parents[left] = right;
            return false;
        }
    }
    int find(vector<int> &parents, int a)
    {
        while(parents[a]!=a)
        {
            a = parents[a];
        }
        return a;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges)
    {
        int n = edges.size();
        vector<int> parents(n+1);
        for(int i = 0 ; i <= n ; i++)
        {
            parents[i] = i;
        }

        for(auto &e : edges)
        {
            int a = e[0], b = e[1];
            if(join(parents,a,b))return {a,b};
        }
        return {};
    }
};
