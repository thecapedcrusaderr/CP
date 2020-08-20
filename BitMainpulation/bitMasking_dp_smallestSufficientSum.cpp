// Yaha se hui na learning meri, dp+bitmasking ka pehla question jisse kuch seekhne ko mila, the concept which i was looking for

class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people)
    {
        int n = req_skills.size();
        unordered_map<string,int> skillIndex;
        for(int i = 0 ; i < n; i++)
        {
            skillIndex[req_skills[i]] = i;
        }

        unordered_map<int,vector<int>> dp;
        dp.reserve(1<<n);
        dp[0] = {};

        int m = people.size();
        for(int i = 0 ; i < m ; i++)
        {
            int sz = people[i].size();
            int skill = 0;
            for(int j = 0 ; j < sz ; j++)
            {
                skill |= 1<<skillIndex[people[i][j]];
            }
            for(auto it : dp)
            {
                int a = it.first;
                int here = skill | a;
                if(!dp.count(here) || dp[here].size() > 1 + dp[a].size())
                {
                    dp[here] = it.second;
                    dp[here].push_back(i);
                }
            }
        }

        return dp[(1<<n) - 1];

    }
};
