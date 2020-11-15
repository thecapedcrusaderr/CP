#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void support(string &s)
{
    int n = s.size();
    vector<vector<int>> dp(n, vector<int> (n, 1));

    for(int i = 0 ; i < n-1 ; i++)
    {
        if(s[i]==s[i+1])dp[i][i+1] = 2;
    }

    for(int len = 2 ; len < n ; len++)
    {
        for(int i = 0 ; i < n- len ; i++)
        {
            if(s[i]==s[i+len])
            {
                dp[i][i+len] = max({2 + dp[i+1][i+len-1], dp[i+1][i+len], dp[i][i+len-1]});
            }
            else
            {
                dp[i][i+len] = max(dp[i+1][i+len], dp[i][i+len-1]);
            }
        }
    }
    ll ans = 0;
    for(int i = 0 ; i < n-1 ; i++)
    {
        ans = max(dp[0][i], dp[i+1][n-1]);
    }
    cout<<ans<<endl;
}

int main()
{
    string s;
    cin>>s;
    support(s);
    return 0;
}
