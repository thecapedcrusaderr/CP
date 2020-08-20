#include<bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int>& heights)
{
  int n = heights.size();
  if(n==0)return 0;

  stack<int> left;
  stack<int> right;

  vector<int> leftDrop(n,-1);
  vector<int> rightDrop(n,-1);

  left.push(-1);
  right.push(-1);
  left.push(0);
  right.push(n-1);

  for(int i = 1 ; i < n ; i++)
  {
    int index = left.top();
    if(heights[i] > heights[index])
    {
      left.push(i);
      leftDrop[i] = index;
    }
    else if(heights[i] == heights[index])
    {
      left.pop();
      leftDrop[i] = left.top();
      left.push(i);
    }
    else
    {
      while(heights[i] < heights[index])
      {
        left.pop();
        index = left.top();
        if(index==-1)break;
      }
      leftDrop[i] = index;
      left.push(i);
    }
  }

  for(int i = n-2; i>=0; i--)
  {
    int index = right.top();
    if(heights[i] > heights[index])
    {
      right.push(i);
      rightDrop[i] = index;
    }
    else if(heights[i] == heights[index])
    {
      right.pop();
      rightDrop[i] = right.top();
      right.push(i);
    }
    else
    {
      while(heights[i] < heights[index])
      {
        right.pop();
        index = right.top();
        if(index==-1)break;
      }
      rightDrop[i] = index;
      right.push(i);
    }
  }

  int ans = 0;
  for(int i = 0 ; i< n ;i++)
  {
    if(leftDrop[i] == -1 && rightDrop[i]==-1)
    {
      ans = max(ans,heights[i]*n);
    }
    else if(leftDrop[i] == -1)
    {
      ans = max(ans, heights[i]*rightDrop[i]);
    }
    else if(rightDrop[i] == -1)
    {
      ans = max(ans, (n-1-leftDrop[i]) * heights[i]);
    }
    else
    {
      ans = max(ans, (rightDrop[i]-leftDrop[i]-1)*heights[i]);
    }
  }
  return ans;
}
int main()
{

}
