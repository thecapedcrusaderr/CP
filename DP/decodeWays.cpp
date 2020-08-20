#include<bits/stdc++.h>
using namespace std;

int numDecodings(string s)
{
    int n = s.size();
    if(n==0)return 0;

    vector<int> ways(n+1,0);

    ways[0] = 1;
    if(int(s[0])-48 == 0)
    {
      return 0;
    }
    else
    {
      ways[1] = 1;
    }

    for(int i = 2; i<=n; i++)
    {
      if(int(s[i-1])-48 != 0)
      {
        ways[i]+=ways[i-1];
        int prev = int(s[i-2])-48;
        int curr = int(s[i-1])-48;
        int num = prev*10+curr;
        if(num>=10 && num<=26)
        {
          ways[i]+=ways[i-2];
        }
      }
      else
      {
        int prev = int(s[i-2])-48;
        if(prev == 1 || prev == 2)
        {
          ways[i]+=ways[i-2];
        }
        else
        {
          return 0;
        }
      }
    }
    return ways[n];
}
