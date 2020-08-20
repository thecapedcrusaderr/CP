#include<bits/stdc++.h>
using namespace std;

// Mast question hai

int findRotateSteps(string ring, string key)
{
    int r = ring.size();
    int k = key.size();

    vector<vector<int>> charIndex(26);

    // Index stored for all the
    for(int i = 0 ; i < r; i++)
    {
      charIndex[ring[i]-'a'].push_back(i);
    }

    vector<int> dp(r,0);

    vector<int> prevInd(1,0);

    for(int i = 0 ; i < k; i++)
    {
        vector<int> currInd = charIndex[key[i]-'a'];
        int currSize = currInd.size();

        for(int j = 0 ; j < currSize; j++)
        {
           int prevSize = prevInd.size();
           int minm = INT_MAX;
           for(int l = 0 ; l < prevSize ; l++)
           {
             minm = min(minm , dp[prevInd[l]] + min(abs(prevInd[l]-currInd[j]), r - abs(prevInd[l]-currInd[j])));
           }
           dp[currInd[j]] = minm;
        }
        // cout<<"yahan aara hai kya "<<endl;
        prevInd = currInd;
    }


    prevInd = charIndex[key.back()-'a'];
    int ans = INT_MAX;

    for(int i = 0 ; i < prevInd.size(); i++)
    {
      ans = min(ans, dp[prevInd[i]]);
    }
    return ans+k;
}
