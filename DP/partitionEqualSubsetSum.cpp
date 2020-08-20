#include<bits/stdc++.h>
using namespace std;

// Good Question

bool canPartition(vector<int>& nums)
{
    int m = nums.size();
    int sum = 0;

    for(int i = 0 ; i < m ;i++)
    {
      sum+=nums[i];
    }
    // cout<<" sum we got is "<<sum<<endl;
    if(sum%2 == 1)return false;
    int n = sum/2+1;
    // cout<<" the value of n we got is "<<n<<endl;

    vector<bool> dpPrev(n);
    vector<bool> dpCurr(n);

    dpPrev[0] = true;
    // cout<<dpPrev[0]<<" ";
    for(int j = 1 ; j < n ; j++)
    {
      dpPrev[j] = false;
      // cout<<dpPrev[j]<<" ";
    }
    // cout<<endl;

    for(int i = 1 ; i <= m ; i++)
    {
      for(int j = 0 ; j < n ;j++)
      {
        if(j!=0)
        {
          if(nums[i-1]-j <= 0)
          {
            dpCurr[j] = dpPrev[j] || dpPrev[j-nums[i-1]];
          }
          // cout<<dpCurr[j]<<" ";
        }
        else
        {
          dpCurr[j] = true;
          // cout<<dpCurr[j]<<" ";
        }
      }
      // cout<<endl;
      for(int i = 0 ; i<n ;i++)
      {
          dpPrev[i] = dpCurr[i];
      }
    }
    return dpPrev[n-1];
}
