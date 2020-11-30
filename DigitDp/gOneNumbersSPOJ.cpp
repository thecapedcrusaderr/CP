#include<bits/stdc++.h>
using namespace std;
int t, l, r;
string str;

int dp[10][2][80];

unordered_set<int> primes = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
void init(int k)
{
    str = to_string(k);
    memset(dp, -1, sizeof(dp));
}

int dfs(int pos, int tight, int sum)
{
    if(pos==str.size())
    {
        if(primes.count(sum))return 1;
        else return 0;
    }

    if(dp[pos][tight][sum]!=-1)return dp[pos][tight][sum];

    int val = 0;
    if(tight)
    {
        int limit = str[pos]-'0';
        for(int i = 0 ; i < limit ; i++)
        {
            val += dfs(pos+1, !tight, sum+i);
        }
        val += dfs(pos+1, tight, sum+limit);
    }
    else
    {
        for(int i = 0 ; i <= 9 ; i++)
        {
            val += dfs(pos+1, tight, sum+i);
        }
    }
    return dp[pos][tight][sum] =  val;
}

int main()
{
    cin>>t;

    while(t--)
    {
        cin>>l>>r;
        --l;
        init(l);
        int first = dfs(0,1,0);
        init(r);
        int second = dfs(0,1,0);
        cout<<second-first<<endl;
    }
    return 0;
}
