// isko dp se krenge

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;
        int cost[n];
        for(int i= 0 ; i < n ; i++)cin>>cost[i];

        vector<int> dp(n+1, 0);

        for(int i = 1 ; i <= n ; i++)
        {
            for(int j = i ; j <= n ; j++)
            {
                dp[j] = max(dp[j], cost[i-1] + dp[j - i]);
            }
        }

        cout<<dp[n]<<endl;
    }
    return 0;
}
