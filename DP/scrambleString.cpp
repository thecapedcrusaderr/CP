// I will do this amazing question of dp by myself.

class Solution {
public:
    bool isScramble(string s1, string s2)
    {
        int n = s1.size();

        vector<bool> kyare(n,false);

        // vector<vector<vector<int>>> dp(n+1, vector<int> (n+1, vector<int> (n+1)));
        bool dp[100][100][100] = {false};

        for(int i = n-1 ; i >= 0 ; i--)
        {
            for(int j = n-1 ; j>=0 ; j--)
            {
                dp[i][j][1] = s1[i]==s2[j];

                for(int len = 2 ; i+len <= n && j+len <= n ; len++)
                {
                    for(int k = 1 ; k < len ; k++)
                    {
                        dp[i][j][len] |= (dp[i][j][k] && dp[i+k][j+k][len-k]);

                        dp[i][j][len] |= (dp[i][j+len-k][k] && dp[i+k][j][len-k]);
                    }
                }
            }
        }
        return dp[0][0][n];
    }
};
