class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid)
    {
        int m = grid.size();
        vector<vector<vector<int>>> dp(m+1, vector<vector<int>> (m+1, vector<int> (m+1,INT_MIN)));

        dp[1][1][1] = grid[0][0];

        for(int x1 = 1; x1 <= m ; x1++)
        {
            for(int y1 = 1 ; y1 <= m ; y1++)
            {
                for(int x2 = 1 ; x2 <= m ; x2++)
                {
                    int y2 = x1+y1-x2;
                    if(y2 < 1 || y2 > m || grid[x1-1][y1-1] == -1 || grid[x2-1][y2-1] == -1 || dp[x1][y1][x2] > 0)continue;

                    int curr = max({dp[x1-1][y1][x2], dp[x1][y1-1][x2-1], dp[x1-1][y1][x2-1], dp[x1][y1-1][x2]});
                    if(curr < 0)continue;
                    dp[x1][y1][x2] = curr + grid[x1-1][y1-1];
                    if(x1 != x2)
                    {
                        dp[x1][y1][x2] += grid[x2-1][y2-1];
                    }
                }
            }
        }
        return dp[m][m][m] < 0 ? 0 : dp[m][m][m];

    }
};
