class Solution {
public:
    int countPrimes(int n)
    {
        if(n <= 2)return 0;
        vector<bool> isPrime(n+1,true);

        int ans = 1;

        for(long i = 3 ; i < n; i+=2)
        {
            if(isPrime[i])
            {
                ans++;
                for(long j = i * i; j <= n ; j = j + 2*i)
                {
                    isPrime[j] = false;
                }
            }
        }
        return ans;
    }
};
