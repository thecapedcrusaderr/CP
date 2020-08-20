#include<bits/stdc++.h>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

    int m = obstacleGrid.size();
    int  n = obstacleGrid[0].size();

    cout<<" m and n is "<<m<<" "<<n<<endl;

  vector<vector<int>> rec(m,vector<int> (n,0));
  if(obstacleGrid[0][0] == 0)
  {
      rec[0][0] = 1;
  }
  else
  {
      return 0;
  }
  for(int i = 1 ; i< n ;i++)
  {
    if(obstacleGrid[0][i] == 1)
    {
        rec[0][i] = 0;
    }
    else
    {
        rec[0][i] = rec[0][i-1];
    }
  }
  for(int i = 1; i< m; i++)
  {
    if(obstacleGrid[i][0] == 1)
    {
        rec[i][0] = 0;
    }
    else
    {
        rec[i][0] = rec[i-1][0];
    }
  }

  cout<<"debugging" <<endl;
  cout<<rec[21][27]<<" "<<rec[20][27]<<" "<<rec[21][26]<<endl;

  for(int i = 1; i < m ; i++)
  {
    for(int j = 1 ; j < n ; j++)
    {
      if(i==21 && j>28)
      {
          cout<<"hello"<<endl;
      }
      if(obstacleGrid[i][j] == 1)
      {
          rec[i][j] = 0;
      }
      else
      {
          rec[i][j]  = rec[i-1][j] + rec[i][j-1];
      }
    }
  }
  return rec[m-1][n-1];
}
int main ()
{
  vector<vector<int>> toSend;
  cin>>toSend;
  int out = uniquePathsWithObstacles(toSend);
  cout<<"final ans is "<<out<<endl;
}
