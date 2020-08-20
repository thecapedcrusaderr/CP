#include<bits/stdc++.h>
using namespace std;


// Basically concept is maintain current max negative product and current max positive product.

int maxProduct(vector<int>& nums)
{
  int n = nums.size();
  if(n==0)return 0;

  if(n==1)return nums[0];

  int overallProduct = INT_MIN;
  int currPosProduct = 1;
  int currNegativeProduct = 1;

  for(int i = 0 ; i < n ;i++)
  {
    if(nums[i]>0)
    {
      currPosProduct = max(currPosProduct * nums[i], nums[i]);
      currNegativeProduct = currNegativeProduct * nums[i];
    }
    else
    {
      int temp1 = currPosProduct , temp2 = currNegativeProduct;
      currPosProduct = temp2 * nums[i];
      currNegativeProduct = min(nums[i],temp1 * nums[i]);
    }

    int maxcurr = max(currPosProduct,currNegativeProduct);

    if(overallProduct < maxcurr)
    {
      overallProduct =  maxcurr;
    }
    if(currPosProduct==0 && currNegativeProduct==0)
    {
        currPosProduct=1;
        currNegativeProduct = 1;
    }
  }
  return overallProduct;
}
