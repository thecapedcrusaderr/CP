#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


ll support(vector<int> &arr, int left, int right, int count)
{
    int last = left, minm = arr[left];
    ll sum;

    for(int i = left ; i <= right ; i++)
    {
        minm = min(minm, arr[i]);
    }
    sum = minm - count;
    for(int i = left ; i <= right ; i++)
    {
        if(arr[i]==minm)
        {
          if(last < i)
          {
            sum+=support(arr, last, i-1, minm);
          }
          last = i+1;
        }
    }
    if(last <= right)sum+=support(arr, last, right, minm);
    return min(right-left+1, sum);
}

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0 ; i < n ; i++)
    {
      cin>>arr[i];
    }
    ll ans = support(arr, 0,n-1,0);
    cout<<ans<<endl;
    return 0;
}
