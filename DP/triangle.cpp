#include<bits/stdc++.h>
using namespace std;

int minimumTotal(vector<vector<int>>& triangle)
{
int m = triangle.size();
if(m==0)return 0;
if(m==1)return triangle[0][0];

vector<int> currDp(m,-1);
vector<int> nextDp(m,-1);
currDp[0] = triangle[0][0];

for(int i = 1 ; i < m; i++)
{
int n = triangle[i].size(), currIndex = 0 ;
for(int j = 0 ; j < n; j++)
{
  if(j==0)
  {
    nextDp[currIndex] = triangle[i][j] + currDp[0];
    currIndex++;
  }
  else if(j==n-1)
  {
    nextDp[currIndex] = triangle[i][j] + currDp[i-1];
  }
  else
  {
    int leftSum = triangle[i][j] + currDp[j-1];
    int rightSum = triangle[i][j] + currDp[j];
    nextDp[currIndex] = min(leftSum,rightSum);
    currIndex++;
  }
}
for(int j = 0; j< n ;j++)
{
  currDp[j] = nextDp[j];
}
}
int minm = INT_MAX;
for(int j = 0 ; j < m ; j++)
{
minm = min(currDp[j],minm);
}
return minm;
}
