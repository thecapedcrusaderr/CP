#include<bits/stdc++.h>
using namespace std;

// We have used dp first in order to find substring till we can make valid sentences, then we have applied dfs as it has reduced our complexity.

vector<string> wordBreak(string s, vector<string>& wordDict)
{
    int n = s.size();
    vector<vector<int>> res(n);

    unordered_set<string> words;
    for(auto word: wordDict)
    {
      words.insert(word);
    }

    vector<bool> dp(n+1,false);
    dp[0] = true;


    for(int i =  0; i < n; i++)
    {
        for(int j = i ; j >=0 ; j--)
        {
            string subString = s.substr(j,i-j+1);
            if(words.find(subString)!=words.end())
            {
                if(dp[j])
                {
                    res[i].push_back(j);
                    dp[i+1]=dp[i+1]||dp[j];
                }
            }
        }
    }

    vector<string> fO;
    dfs(s,res,"",n-1,fO);
    return fO;
}

void dfs(string s, vector<vector<int>>& res, string output, int currIndex, vector<string>& fO)
{
    for(int i = 0 ; i < res[currIndex].size(); i++)
    {
        string sub = s.substr(res[currIndex][i],currIndex-res[currIndex][i]+1);
        if(res[currIndex][i] == 0)
        {
            if(output=="")
            {
                fO.push_back(sub);
            }
            else
            {
                fO.push_back(sub+" "+output);
            }
        }
        else
        {
            if(output=="")
            {
                dfs(s,res,sub,res[currIndex][i]-1,fO);
            }
            else
            {
                dfs(s,res,sub+" "+output,res[currIndex][i]-1,fO);
            }
        }
    }
}
