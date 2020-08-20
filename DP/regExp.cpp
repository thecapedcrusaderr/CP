#include<bits/stdc++.h>
using namespace std;

bool isMatch(string s, string p)
{
  int sLen = s.size();
  int pLen = p.size();

  vector< vector<bool>> status(sLen+1, vector<bool> (pLen+1,false));

  status[0][0] = true;

  for(int i = 1;i<=pLen;i++)
  {
    if(p[i-1] == '*')
    {
      status[0][i] = status[0][i-2];
    }
  }

  for(int i = 1; i <= sLen; i++)
  {
    for(int j = 1 ; j <= pLen ; j++)
    {
      if(s[i-1] == p[j-1] || p[j-1] == '.')
      {
        status[i][j] = status[i-1][j-1];
      }
      else if(p[j-1] == '*')
      {
        if(s[i-1] == p[j-2] || p[j-2] == '.')
        {
          status[i][j] = status[i][j-2] || status[i-1][j];
        }
        else
        {
          status[i][j] = status[i][j-2];
        }
      }
      else
      {
        status[i][j] =  false;
      }
    }
  }

  // cout<<"printing status "<<endl;
  // for(int i = 0; i<sLen+1 ; i++)
  // {
  //   for(int j = 0; j<pLen+1 ; j++)
  //   {
  //     cout<<status[i][j]<<" ";
  //   }
  //   cout<<endl;
  // }

  return status[sLen][pLen];
}
int main()
{
  string s = "aa";
  string p = "a*";
  bool out = isMatch(s,p);
  if(out == true)cout<<"sahi"<<endl;
  else cout<<"galat";
}
