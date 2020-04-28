#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int support(int n)
{
  int k = 1;
  if(n==1)return 1;
  else if(n==2)return 2;
  else
  {
    while(n>=pow(2,k))
    {
      k++;
    }
    return k;
  }
}

int main()
{
  int n,p,lower_B,upper_B;
  int k,x=1;
  vector<vector<int>> table;
  cout<<"Enter the size of array you want"<<endl;
  cin>>n;
  int data[n];
  for(int i = 0;i<n;i++)
  {
    cin>>data[i];
  }

  k=support(n);
  table.resize(n);
  for(int i = 0;i<n;i++)
  {
    table[0].push_back(data[i]);
  }
  k--;
  int y = 1,z=1;
  while(k--)
  {
      int i = 0;
      while(i+y<n)
      {
        table[z].push_back(min(table[z-1][i],table[z-1][i+y]));
        i++;
      }
    z++;
    y=2*y;
  }

  cout<<"enter the left and right index for minimum"<<endl;
  cin>>lower_B>>upper_B;

  int needed = support(upper_B-lower_B+1);
  cout<<"Final answer is "<<min(table[needed-1][lower_B],table[needed-1][upper_B-needed+1]);

  return 0;
}
