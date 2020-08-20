#include<bits/stdc++.h>
using namespace std;

bool isMatch(string s, string p)
{
  int sLen = s.size();
  int pLen = p.size();

  vector< vector<bool>> support(sLen+1, vector<bool> (pLen+1, false));
  support[0][0] = true;

  for(int i = 1; i <= pLen ; i++)
  {
    if(p[i-1]=='*')support[0][i] = support[0][i-1];
  }

  for(int i = 1 ; i <= sLen ; i++)
  {
    for(int j = 1 ; j <= pLen ; j++)
    {
      if(s[i-1] == p[j-1] || p[j-1] == '?')
      {
        support[i][j] =  support[i-1][j-1];
      }
      else if(p[j-1] == '*')
      {
        support[i][j] = support[i][j-1] || support[i-1][j];
      }
      else
      {
        support[i][j] = false;
      }
    }
  }
  return support[sLen][pLen];
}

int main()
{
  string s = "adceb";
  string p = "*a*b";
  bool out = isMatch(s,p);
  if(out == true)cout<<"sahi";
  else cout<<"galat";
}
