long knock(long int n, long positions[], long heights[])
{
    vector<vector<int>> dp(3, vector<long>(n, 0)); // dp of 3 X n

    dp[0][0] = 1;  // O-th domino can fall on left without any issue
    dp[1][0] = 0; // if 0-th domino stand, then ans is 0
    dp[2][0] = 0; // we don’t know this, so let’s find out

    // 0-th domino can fall to right only if it doesn’t interfere with 1st domino or
    // if there is only 1 domino
    if((n > 1 && positions[0] + heights[0] < positions[1] || n == 1)) dp[2][0] = 1;
    for(int i = 1; i < n; ++i)
    {
    	// if i-th domino can fall on left. This is a necessary condition
        if(positions[i] - heights[i] > positions[i - 1])
        {
        	// if (i-1)th falls on right and i-th falls on left without interfering
            if(positions[i - 1] + heights[i - 1] < positions[i] - heights[i])
                dp[0][i] = 1 + max({dp[0][i - 1], dp[1][i - 1], dp[2][i - 1]});
            else
                dp[0][i] = 1 + max(dp[0][i - 1], dp[1][i - 1]);
        }
        // if i-th don’t fall, then take maximum from previous state
        dp[1][i] = max({dp[0][i - 1], dp[1][i - 1], dp[2][i - 1]});

        // i-th domino can fall on right if it is the last domino or if it
 // doesnt not interfere with (i+1)th domino's position.
        if(i == n - 1 || positions[i] + heights[i] < positions[i + 1])
            dp[2][i] = 1 + max({dp[0][i - 1], dp[1][i - 1], dp[2][i - 1]});
    }
    return max({dp[0][n - 1], dp[1][n - 1], dp[2][n - 1]});
}
