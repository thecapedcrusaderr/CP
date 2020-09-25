class Solution {
public:

    string returnMax(string &s1, string &s2)
    {
        if(s1.size() < s2.size())return s2;
        else if(s2.size() < s1.size())return s1;
        else
        {
            if(s1 > s2)return s1;
            else return s2;
        }
    }

    string largestNumber(vector<int>& cost, int target)
    {
        vector<vector<string>> dp(10, vector<string> (target+1, "0"));
        for(int i = 0 ; i < 10 ; i++)
        {
            dp[i][0] = "";
        }

        for(int i = 1 ; i < 10; i++)
        {
            for(int j = 1 ; j <= target ; j++)
            {
                dp[i][j] = dp[i-1][j];

                if(cost[i-1] <= j)
                {
                    string temp;
                    if(dp[i][j-cost[i-1]] != "0")
                    {
                        temp = to_string(i) + dp[i][j-cost[i-1]];
                        dp[i][j] = returnMax(dp[i][j], temp);
                    }
                }
            }
        }
        return dp[9][target];
    }
};

    
