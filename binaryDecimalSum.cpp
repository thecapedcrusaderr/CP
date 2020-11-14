#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, ans, first, second, curr;
int m = 1e9+7;

int main()
{
    ll powSupp[62];
    ll powTwo[62];
    powSupp[0] = 1;
    powTwo[0] = 1;
    for(int i = 1 ; i <= 61; i++)
    {
        powSupp[i] = (10 * powSupp[i-1])%m;
        powTwo[i] = (2 * powTwo[i-1]);
    }
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        ans = 0;
        ans += ceil(n/2.0);
        for(int i = 2 ; i <= 61 ; i++)
        {
            first = powTwo[i], second = powTwo[i-1];
            if(second > n)break;
            curr = (n/first)*second;
            if( (n % first) >= second-1)
            {
                curr += (n%first)-(second-1);
            }
            curr %= m;
            ans = (ans + (curr * powSupp[i-1])%m)%m;
        }
        cout<<ans<<endl;
    }
    return 0;
}
