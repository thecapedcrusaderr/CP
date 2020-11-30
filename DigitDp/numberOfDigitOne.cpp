
// dhanshu question digit dp zindabad tha hai rhega
// ye khud se kra hai bhai...
class Solution {
public:
    int dp[12][2][12];
    string num;

    int fun(int pos, int tight, int count)
    {
        if(pos==num.size())return count;

        if(dp[pos][tight][count]!=-1)return dp[pos][tight][count];

        int val = 0;

        for(int i = 0 ; i <= 9 ; i++)
        {
            if(num[pos]-'0' > i)
            {
                if(i==1)
                {
                    val += fun(pos+1, 0, count+1);
                }
                else
                {
                    val += fun(pos+1, 0, count);
                }
            }
            else if(num[pos]-'0'==i)
            {
                if(tight)
                {
                    if(i==1)
                    {
                        val += fun(pos+1, 1, count+1);
                    }
                    else
                    {
                        val += fun(pos+1, 1, count);
                    }
                }
                else
                {
                    if(i==1)
                    {
                        val += fun(pos+1, 0, count+1);
                    }
                    else
                    {
                        val += fun(pos+1, 0, count);
                    }
                }
            }
            else
            {
                if(!tight)
                {
                    if(i==1)
                    {
                        val += fun(pos+1, 0, count+1);
                    }
                    else
                    {
                        val += fun(pos+1, 0, count);
                    }
                }
            }
        }

        return dp[pos][tight][count] = val;
    }

    int countDigitOne(int n)
    {
        num = to_string(n);
        memset(dp, -1, sizeof(dp));
        return fun(0, 1, 0);
    }
};
