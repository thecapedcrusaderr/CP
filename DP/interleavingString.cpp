#include<bits/stdc++.h>
using namespace std;

bool isInterleave(string s1, string s2, string s3)
{
   int m = s1.size();
   int n = s2.size();
   int size = s3.size();

   if(m+n != size)
   {
       return false;
   }
   vector<vector<bool>> dp(1,vector<bool> (n+1,0));

   dp[0][0] = true;
   for(int j = 1; j < n+1 ; j++)
   {
      dp[0][j] = (s2[j-1]==s3[j-1] ? dp[0][j-1] : false);
   }

   for(int i = 1 ; i < m+1 ; i++)
   {
     dp[0][0] = s1[i-1]==s3[i-1] ? dp[0][0] : false;
     for(int j = 1 ; j < n+1 ; j++)
     {
       dp[0][j] = (s3[i+j-1] == s1[i-1] ? dp[0][j] : false) || (s3[i+j-1] == s2[j-1] ? dp[0][j-1] : false);
     }
   }
   return dp[0][n];
}
