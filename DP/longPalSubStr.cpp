#include<bits/stdc++.h>
using namespace std;

string longestPalindrome(string s) {
        int n = s.size();
        int low = -1, high = -1, longest = 0;
        vector<vector<bool>> isPal(n, vector<bool> (n,false));

        for(int i = 0; i<n;i++)
        {
            for(int j = 0; j<=i ; j++)
            {
                if (s[j] == s[i])
                {
                    if(i==j)
                    {
                        isPal[i][j]=true;
                    }
                    else if(i-j == 1)
                    {
                       isPal[i][j] = true;
                       if( (i-j+1) > longest )
                       {
                           // cout<<"fir yahan kaise nahin aa rha "<<endl;
                           longest = i-j+1;
                           low = j, high = i;
                       }
                    }
                    else
                    {
                        if(isPal[i-1][j+1] == true)
                        {
                            isPal[i][j] = true;
                            if( (i-j+1) > longest )
                            {
                                // cout<<"fir yahan kaise nahin aa rha "<<endl;
                                longest = i-j+1;
                                low = j, high = i;
                            }
                        }
                    }
                }
            }
        }

    // for(int i = 0;i<n;i++)
    // {
    //   for (int j = 0;j<=i;j++)
    //   {
    //     cout<<isPal[i][j]<<" ";
    //   }
    //   cout<<endl;
    // }

    string out = "";
    if(low!=-1)
    for(int i = low; i<=high; i++)
    {
        out += s[i];
    }
    else
    {
      if(n!=0)
      out = s[0];
    }
    return out;
}
int main()
{
  string sen;
  cin>>sen;
  // string sen = "babad";
  string fin = longestPalindrome(sen);
  cout<<fin;
  return 0;
}
