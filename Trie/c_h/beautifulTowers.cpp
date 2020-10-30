#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, a, r, m;

ll binarySupport(vector<int> &arr, ll height)
{
    ll toAdd = 0, toRemove = 0, ans = 0;
    for(int i = 0 ; i < n ; i++)
    {
        toAdd += max(height-arr[i], 0);
        toRemove += max(arr[i] - height, 0);
    }
    ll common = mid(toAdd, toRemove);
    ans += common * m;
    toAdd -= common;
    toRemove -= common;

    ans += toAdd * a;
    ans += toRemove * r;
    return ans;
}

int main()
{
    cin>>n>>a>>r>>m;
    vector<int> arr(n);
    for(int i = 0 ; i < n ; i++)
    {
        cin>>arr[i];
    }
    m = min(m, a+r);
    sort(arr.begin(),arr.end());

    int low = 1, high = 1e9;
    while(low <= high)
    {
        ll mid = low + (high-low)/2;
        ll first = binarySupport(arr, mid), second = binarySupport(arr, mid+1);
        if(first > second)low = mid+1;
        else high = mid-1;
    }
    ll out = support(arr, low);
    cout<<out<<endl;
    return 0;
}
