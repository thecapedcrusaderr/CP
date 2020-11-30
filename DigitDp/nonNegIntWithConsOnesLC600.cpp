class Solution {
public:
    int dp[32][2][2];
    vector<int> bits;

    // ek prev kya tha uske liye, ek bada hai ya nahin uske liye, tight wala concept.
    // ye flag btara ki chota hai ya nahin, prev btara prev bit pe kya hai

    int fun(int pos, int flag, int prev)
    {
        if(pos==bits.size())return 1;

        if(dp[pos][flag][prev]!=-1)return dp[pos][flag][prev];

        int val = 0;

        if(bits[pos]==0)val += fun(pos+1, flag, 0);
        else val += fun(pos+1, 1, 0);

        // 1 tabhi put krenge jb prev 0 rhe
        if(prev==0)
        {
            if(flag==1)
            {
                // mtlb chota hai, to chota hi rhega, so same flag pass hogya
                val += fun(pos+1, flag, 1);
            }
            else
            {
                // mtlb barabar hai, to ab ek hi option hai
                if(bits[pos]==1)
                {
                    val += fun(pos+1, false, 1);
                }
            }
        }
        return dp[pos][flag][prev] = val;

    }

    int findIntegers(int num)
    {
        while(num)
        {
            bits.push_back(num%2);
            num/=2;
        }
        reverse(bits.begin(),bits.end());
        memset(dp, -1, sizeof(dp));
        return fun(0,0,0);
    }
};
