#include<bits/stdc++.h>
using namespace std;

int minDistance(string word1, string word2)
{
   int m = word1.size();
   int n = word2.size();

   vector<vector<int>> dist(m+1,vector<int> (n+1,0));

   for(int i = 1 ; i < n+1 ; i++)
   {
     dist[0][i] = i;
   }
   for(int i = 1 ; i < m+1 ; i++)
   {
     dist[i][0] = i
   }

   for(int i = 1 ; i< m+1; i++)
   {
     for(int j = 1 ; j<n+1; j++)
     {
       if(word1[i-1] == word2[j-1])
       {
         dist[i][j] = dist[i-1][j-1];
       }
       else
       {
         dist[i][j] = 1 + min(dist[i-1][j-1],min(dist[i-1][j], dist[i][j-1]));
       }
     }
   }
   return dist[m][n];
}
