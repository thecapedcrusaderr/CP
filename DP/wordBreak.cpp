#include<bits/stdc++.h>
using namespace std;

bool wordBreak(string s, vector<string>& wordDict)
{
    int n = wordDict.size();
    unordered_set<int> words:
    for(auto word : wordDict)
    {
      words.insert(word);
    }

    vector<bool> dp(n+1,false);
    dp[0] = true;

    for(int i = 0 ; i < n; i++)
    {
      for(int j = i ; j >= 0 ; j--)
      {
        if(words.find(s.substr(j,i-j+1))!=words.end())
        {
          dp[i+1] = dp[j];
        }
        if(dp[i+1])break;
      }
    }
    return dp[n];
}
