#include<bits/stdc++.h>
#define m 1000000007
using namespace std;

int main()
{

  vector<int> prime(8192,1);
  prime[0] = 0, prime[1] = 0;

  for(int num = 3; num < 8192 ; num++)
  {
    if(num%2==0)
    {
        prime[num]=0;
        continue;
    }
    for(int j = 3; j*j <= num ;j++)
    {
        if(num%j == 0)
        {
            prime[num] = 0;
            break;
        }
    }
  }

  int q;
  cin>>q;

  while(q--)
  {
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0 ; i < n ; i++)
    {
      cin>>arr[i];
    }
    vector<long long> count(1001,0);
    for(int i = 0 ; i < n ;i++)
    {
      count[arr[i]-3500]++;
    }
    vector<vector<long long>> dp(1001, vector<long long> (8192,0));

    dp[0][0] = (count[0] + 2)/2;
    dp[0][3500] = (count[0] + 1)/2;

    for(int i = 1; i < 1001; i++)
    {
      for(int j = 0 ; j < 8192 ; j++)
      {
        dp[i][j] = ((dp[i-1][j] * ((count[i] + 2)/2))%m + (dp[i-1][j^(i+3500)] * (((count[i]+1)/2)%m)))%m;
      }
    }

    // cout<<"is 3511 a prime number "<<prime[3511]<<endl;

    long long ans = 0;
    for(int j = 0 ; j < 8192 ; j++)
    {

      if(prime[j] != 0)
      {
        ans += dp[1000][j];
        ans = ans % m;
      }
    }
    cout<<ans%m<<endl;
  }
  return 0;
}
