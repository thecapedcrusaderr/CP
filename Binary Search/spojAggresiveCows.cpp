#include<bits/stdc++.h>
using namespace std;

bool validBinary(vector<long long> &arr, long long reqd, long long dis)
{
    long long count = 0;
    long long minm = arr[0];
    for(int i = 1 ; i < arr.size(); i++)
    {
        if(arr[i]-minm >= dis)
        {
          count++;
          minm = arr[i];
        }
    }
    if(count!=0)count++;
    return count>=reqd;
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
      int n , c;
      cin>>n>>c;
      if(n <= 1)return 0;
      vector<long long> arr(n);
      for(int i = 0 ; i < n ; i++)
      {
        cin>>arr[i];
      }

      sort(arr.begin(),arr.end());
      long long low = 0, high = arr[n-1]-arr[0];
      long long ans = 0;

      while(low <= high)
      {
        long long mid = low + (high-low)/2;
        cout<<" mid we got is "<<mid<<endl;
        if(validBinary(arr, c, mid))
        {
          ans = mid;
          low = mid+1;
        }
        else
        {
          high = mid-1;
        }
      }

      cout<<ans<<endl;
    }

    return 0;
}
