#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;

	while(t--)
	{
	    int n, w;
	    cin>>n>>w;

	    vector<pair<int,int>> pairs(n);
	    for(int i = 0 ; i < n ;i++)
	    {
	        pairs[i].first = -1, pairs[i].second = -1;
	    }

	   // cout<<" taking values "<<endl;
	    for(int i = 0 ; i < n ; i++)
	    {
	        int a;
	        cin>>a;
	       // cout<<a<<" ";
	        pairs[i].second = a;
	    }
	   // cout<<endl<<" taking weights "<<endl;
	    for(int i = 0 ; i < n ; i++)
	    {
	        int b;
	        cin>>b;
	       // cout<<b<<" ";
	        pairs[i].first = b;
	    }
	   // cout<<endl;

	    sort(pairs.begin(),pairs.end());

	    vector<vector<int>> dp(n,vector<int> (w+1, 0));

	    for(int i = 1 ; i<= w ; i++)
	    {
	        if(i >= pairs[0].first)
	        {
	            dp[0][i] = pairs[0].second;
	        }
	    }

	    int ans = 0;

	    for(int i = 1 ; i < n ; i++)
	    {
	        for(int j = 1 ; j <= w ; j++)
	        {
	            if(j < pairs[i].first)
	            {
	                dp[i][j] = dp[i-1][j];
	                ans = max(ans, dp[i][j]);
	                continue;
	            }

	            dp[i][j] = max(dp[i-1][j], pairs[i].second + dp[i-1][j - pairs[i].first]);
	            ans = max(ans, dp[i][j]);
	        }
	    }
	    cout<<ans<<endl;

	}
	return 0;
}
