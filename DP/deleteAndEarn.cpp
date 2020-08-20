#include<bits/stdc++.h>
using namespace std;

int deleteAndEarn(vector<int>& nums)
{
  int n = nums.size();
  if(n==0)return 0;

  vector<int> count(10001, 0);
  for(auto number : nums)
  {
    count[number]+=1;
  }

  vector<int> take(10001, 0);
  vector<int> skip(10001, 0);

  int maxm = 0;

  for(int i = 1; i <= 10000 ; i++)
  {
    take[i] = skip[i-1] + count[i] * i;
    skip[i] = max(skip[i-1], take[i-1]);
    int hereMax = max(take[i], skip[i]);
    maxm = max(maxm, hereMax);
  }
  return maxm;
}
