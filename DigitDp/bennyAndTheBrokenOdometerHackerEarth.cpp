// Khud se krenge, to hi maja aaega.

class Solution {
public:

    vector<int> digit;
    string num;
    int dp[15][2];

    void init(int n)
    {
        num = to_string(n);
        memset(dp, -1 , sizeof(dp));
    }

    int dfs(int pos, int tight)
    {
        if(pos==num.size())
        {
            return  1;
        }

        if(dp[pos][tight]!=-1)return dp[pos][tight];

        int val = 0;

        int k = digit.size(), limit = num[pos]-'0';

        if(tight==0)
        {
            for(int i = 0 ; i < k ; i++)
            {
                if(digit[i] < limit)
                {
                    val += dfs(pos+1, 1);
                }
                else if(digit[i]==limit)
                {
                    val += dfs(pos+1, 0);
                }
            }
        }
        else
        {
            for(int i = 0 ; i < k; i++)
            {
                val += dfs(pos+1, tight);
            }
        }
        return dp[pos][tight] = val;
    }

    int atMostNGivenDigitSet(vector<string>& digits, int n)
    {
        int k = digits.size();
        for(int i = 0 ; i < k ; i++)
        {
            digit.push_back(digits[i][0]-'0');
        }
        init(n);

        int len = num.size();

        int ans = dfs(0,0);

        for(int i = 1 ; i < len ; i++)
        {
            ans += dfs(i,1);
        }

        return ans;
    }
};
