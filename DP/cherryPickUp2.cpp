class Solution {
public:

    int returnMax(vector<vector<vector<int>>> &dp, vector<vector<int>> &grid, int x, int y1, int y2)
    {
        int m = grid.size(), n = grid[0].size();

        int dirn[3] = {-1,0,1};

        int ans = -1;


        for(int i = 0 ; i < 3 ; i++)
        {
            for(int j = 0 ; j < 3 ; j++)
            {
                int y1Temp = y1 + dirn[i], y2Temp = y2 + dirn[j];
             if(y1Temp < 0 || y1Temp >= n || y2Temp < 0 || y2Temp >=n || dp[x-1][y1Temp][y2Temp] <0)continue;

                if(y1==y2)
                {
                    ans = max(ans, dp[x-1][y1Temp][y2Temp]+grid[x][y1]);
                }
                else
                {
                    ans = max(ans, dp[x-1][y1Temp][y2Temp]+grid[x][y1]+grid[x][y2]);
                }
            }
        }
        // cout<<" ans is "<<ans<<" for x = "<<x<<" and y1 = "<<y1<<" and y2 = "<<y2<<endl;
        return ans;
    }

    int cherryPickup(vector<vector<int>>& grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>> (n, vector<int> (n,-1)));
        dp[0][0][n-1] = grid[0][0] + grid[0][n-1];

        for(int x = 1 ; x < m ; x++)
        {
            for(int y1 = 0;  y1 < n ; y1++)
            {
                for(int y2 = 0 ; y2 < n ; y2++)
                {
                    dp[x][y1][y2] = returnMax(dp, grid, x, y1, y2);
                }
            }
        }

        int ans = INT_MIN;
        for(int j = 0 ; j < n ; j++)
        {
            for(int k = 0 ; k < n ; k++)
            {
                // cout<<dp[m-1][j][k]<<" ";
                ans = max(ans, dp[m-1][j][k]);
            }
        }
        return ans < 0 ? 0 : ans;
    }
};
