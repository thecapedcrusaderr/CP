int removeBoxes(vector<int>& boxes)
{
      int n = boxes.size();

      int dp[n][n][n];

      memset(dp, 0, n*n*n * sizeof(int));

      // Here we are calculating for this array length wise
      // One of the toughest question i have came across

      for(int length = 0; length < n ; length++)
      {
        for(int j = length ; j < n ;j++)
        {
          int i = j - length;

          for(int k = 0 ; k <= i ; k++)
          {
            int res = (k+1)*(k+1);
            if(i<j)
            {
              res+=dp[i+1][j][0];
            }

            for(int m = i+1; m <= j ; m++)
            {
              if(boxes[m]==boxes[i])
              {
                res = max(res, dp[i+1][m-1][0] + dp[m][j][k+1]);
              }
            }
          dp[i][j][k] = res;
          }
        }
      }
      return dp[0][n-1][0];
}
