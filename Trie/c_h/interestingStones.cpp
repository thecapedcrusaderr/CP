// Iska soln worst case me O(n^2) hai
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;

ll traverseLeft(vector<int> &arr, int i)
{
  ll ans = 0;
  for(int j = i-1 ; j >= 0 ; j--)
  {
      if(arr[j] > arr[i])break;
      ans+=arr[j];
  }
  return ans;
}

ll traverseRight(vector<int> &arr, int i)
{
  ll ans = 0;
  for(int j = i+1 ; j < n ; j++)
  {
    if(arr[j] > arr[i])break;
    ans+=arr[j];
  }
  return ans;
}

int main()
{
    cin>>n;
    vector<int> arr(n);
    for(int i = 0 ; i < n ; i++)
    {
        cin>>arr[i];
    }

    ll ans = 0;
    for(int i = 0 ; i < n ; i++)
    {
        ll left = traverseLeft(arr, i), right = traverseRight(arr, i);
        ans = max(ans, left+right);
    }
    cout<<ans<<endl;
    return 0;
}
