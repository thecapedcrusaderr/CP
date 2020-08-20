#include<bits/stdc++.h>
using namespace std;
int coinChange(vector<int>& coins, int amount)
{
 if(amount <= 0)return 0;
 int n = coins.size();
 vector<int> dp(amount+1,0);

 for(int i = 1 ; i <= amount ; i++)
 {
   // cout<<endl<<i<<endl;
   for(int j = 0 ; j < n ; j++)
   {
     // cout<<"j is "<<j<<" ";
     if(i > coins[j])
     {
       if(dp[i-coins[j]] != 0)
       {
         if(dp[i] == 0)
         {
           dp[i] = 1 + dp[i-coins[j]];
         }
         else
         {
           dp[i] = min(dp[i],1+dp[i-coins[j]]);
         }
       }
     }
     else
     {
       if(i == coins[j])
       {
         if(dp[i]==0)
         {
           dp[i] = 1 + dp[i-coins[j]];
         }
         else
         {
           dp[i] = min(dp[i], 1+dp[i-coins[j]]);
         }
       }
     }
   }
 }
 if(dp[amount] == 0)return -1;
 else return dp[amount];
}
int main()
{

}
