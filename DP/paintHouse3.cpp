class Solution {
public:

    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target)
    {
        vector<vector<vector<int>>> dp(m, vector<vector<int>> (target+1, vector<int> (n+1,-1)));

        cout<<dp[0][0][0]<<endl;

        if(houses[0]==0)
        {
            for(int i = 1 ; i <= n ; i++)
            {
                dp[0][1][i] = cost[0][i-1];
            }
        }
        else
        {
            dp[0][1][houses[0]] = 0;
        }

        for(int i = 1 ; i < m ; i++)
        {
            for(int j = 1; j <= target; j++)
            {
                for(int k = 1 ; k <= n ; k++)
                {
                    if(houses[i]!=0 && k != houses[i])
                    {
                        continue;
                    }

                    for(int l = 1 ; l <= n ; l++)
                    {
                        if( l!=k && dp[i-1][j-1][l] != -1)
                        {
                            dp[i][j][k] = dp[i][j][k]==-1 ? dp[i-1][j-1][l] : min(dp[i][j][k], dp[i-1][j-1][l]) ;
                        }
                        else if(l==k && dp[i-1][j][l] != -1)
                        {
                            dp[i][j][k] = dp[i][j][k]==-1 ? dp[i-1][j][l] : min(dp[i][j][k], dp[i-1][j][l]) ;
                        }
                    }
                    if(dp[i][j][k] != -1 && houses[i]!=k)
                    {
                        dp[i][j][k] += cost[i][k-1];
                    }
                }
            }
        }
        int ans = -1;
        for(int i = 1; i <= n ; i++)
        {
            if(dp[m-1][target][i] != -1)
            {
                ans = ans==-1 ? dp[m-1][target][i] :min(ans, dp[m-1][target][i]);
            }
        }
        return ans;
    }
};
