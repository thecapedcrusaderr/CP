// I think i have got zist of how bitmask + dp would be applied here. But i am not sure, if i have mastered it.
// Let's solve it.

// One of the best question of dp+bitmasking here.

class Solution {
public:
    int numberWays(vector<vector<int>>& hats)
    {
        int m = 1e9+7;
        int n = hats.size();
        vector<vector<int>> hatsToPerson(40);

        for(int i = 0; i < n ; i++)
        {
            for(int j = 0 ; j < hats[i].size(); j++)
            {
                hatsToPerson[hats[i][j]-1].push_back(i);
            }
        }

        vector<long> dp(1<<n);
        dp[0] = 1;

        for(int i = 0 ; i < 40 ; i++)
        {
            for(int comb = (1<<n) -1 ; comb >= 0 ; comb--)
            {
                for(auto &nex : hatsToPerson[i])
                {
                    if( (comb & (1<<nex)) == 0)
                    {
                        dp[comb|1<<nex] += dp[comb];
                        dp[comb|1<<nex] %= m;
                    }
                }
            }
        }
        return dp[(1<<n) - 1];
    }
};
