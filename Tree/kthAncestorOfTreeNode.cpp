// We will use this new technique of binary lifting to solve this kth ancestor of tree node. We would save parent of every logarithimic

class TreeAncestor {
public:
    int pSize;
    vector<vector<int>> dp;
    vector<int> par;
    TreeAncestor(int n, vector<int>& parent)
    {
        par.resize(parent.size());
        par = parent;
        int k = ceil(log2(n)) + 1;
        dp.resize(n, vector<int> (k,-1));

        for(int i = 0 ; i < n ;i++)
        {
            dp[i][0] = parent[i];
        }
        for(int i = 0; i < n ; i++)
        {
            for(int j = 1 ; j < k ; j++)
            {
                if(dp[i][j-1]!=-1)
                {
                    dp[i][j] = dp[dp[i][j-1]][j-1];
                }
            }
        }
    }

    int getKthAncestor(int node, int k)
    {
        while(k > 0 and node != -1)
        {
            int ind = floor(log2(k));
            node = dp[node][ind];
            k -= (1 << ind);
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
