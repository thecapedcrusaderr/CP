#include<bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  cin>>t;

  for(int i = 1 ; i<=t; i++)
  {
    int r, c;
    cin>>r>>c;

    vector<string> arr(r);

    for(int j = 0; j<r; j++)
    {
      cin>>arr[j];
    }
    bool flag = true;


    vector<vector<bool>> dominatrix(26,vector<bool> (25,false));

    for(int j = r-2 ; j>=0; j--)
    {
      if(flag ==false)break;
      if(j==r-2)
      {
        for(int l = 0 ; l < c ; l++)
        {
          int pre = arr[j][l]-'A';
          int nex = arr[j+1][l]-'A';
          dominatrix[pre][nex] = true;
        }
      }
      else
      {
        for(int l = 0 ; l < c; l++)
        {
          int pre = arr[j][l]-'A';
          int nex = arr[j+1][l]-'A';

          if(dominatrix[nex][pre] == true)
          {
            flag = false;
            break;
          }
          else
          {
            dominatrix[pre][nex] = true;
          }
        }
      }
    }

    vector<int> output(26,-1);

    if(flag==false)
    {
      cout<<"Case #"+i+": -1"<<endl;
    }
    else
    {

    }
  }

  return 0;
}
