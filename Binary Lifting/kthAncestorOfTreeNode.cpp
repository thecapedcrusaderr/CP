class TreeAncestor {
public:

    vector<vector<int>> dp;

    TreeAncestor(int n, vector<int>& parent)
    {
        int k = floor(log2(n)) + 1;
        dp.resize(n, vector<int> (k,-1));

        for(int i = 0 ; i < n ; i++)
        {
            dp[i][0] = parent[i];
        }

        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 1 ; j < k ; j++)
            {
                if(dp[i][j-1] == -1)break;
                dp[i][j] = dp[dp[i][j-1]][j-1];
                if(dp[i][j]==-1)break;
            }
        }
    }

    int getKthAncestor(int node, int k)
    {
        while(node != -1 && k > 0)
        {
            int here = log2(k);
            node = dp[node][here];
            k -= 1<<here;
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
