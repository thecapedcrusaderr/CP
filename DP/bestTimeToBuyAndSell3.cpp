#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices)
{
  int n = prices.size();
  if(n==0 || n==1)return 0;

  vector<int> intervalMaxFor(n,0);
  vector<int> intervalMaxBack(n,0);

  int minIndex = 0;
  for(int i = 1; i < n ; i++)
  {
    if(prices[i]-prices[minIndex] >  intervalMaxFor[i-1])
    {
      intervalMaxFor[i] = prices[i]-prices[minIndex];
    }
    else
    {
      intervalMaxFor[i] = intervalMaxFor[i-1];
    }

    if(prices[i] < prices[minIndex])
    {
      minIndex = i;
    }
  }
  int maxIndex = n-1;
  for(int i = n-2; i>=0 ; i--)
  {
    if(prices[maxIndex] - prices[i] > intervalMaxBack[i+1])
    {
      intervalMaxBack[i] = prices[maxIndex] - prices[i];
    }
    else
    {
      intervalMaxBack[i] = intervalMaxBack[i+1];
    }

    if(prices[i] > prices[maxIndex])
    {
      maxIndex = i;
    }
  }
  int ans = 0;
  for(int i = 0 ; i < n-1; i++)
  {
    if(intervalMaxFor[i] + intervalMaxBack[i+1] > ans)
    {
      ans = intervalMaxFor[i] + intervalMaxBack[i+1];
    }
  }

  if(intervalMaxFor[n-1] > ans)
  {
      return intervalMaxFor[n-1];
  }
  else
  {
    return ans;
  }

}

int main()
{

}
