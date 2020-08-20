#include<bits/stdc++.h>
using namespace std;

int maximalRectangle(vector<vector<char>>& matrix)
{
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> status(m,vector<int> (n,0));

    for(int i = 0; i < n ;i++)
    {
       if(matrix[0][i] == '1')status[0][i] = 1;
       else status[0][i] = 0;
    }

    for(int i = 1 ; i < m; i++)
    {
      for(int j = 0 ; j < n ; j++)
      {
        if(matrix[i][j] == '1')
        {
          status[i][j] = status[i-1][j]+1;
        }
        else
        {
          status[i][j] = 0;
        }
      }
    }

    int ans = 0;
    for(int i = 0 ; i < m ; i++)
    {
      for(int j = 0 ; j < n ; j++)
      {
        int count = 0, minm = 0;
        for(int k = j ; k < n ; k++)
        {
            if(k==j && status[i][k] != 0)
            {
              minm = status[i][k];
              count++;
              ans = max(ans, minm*count);
            }
            else
            {
              minm = min(status[i][k],minm);
              count++;
              ans = max(ans, minm*count);
            }
        }
      }
    }
    return ans;
}
int main()
{
  return 0;
}
