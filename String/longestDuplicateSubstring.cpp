// We have used Rabin Karp algorithm of string matching here 

class Solution {
public:

    int m = 1e9+7;
    string support(int size, string &S)
    {
        unsigned long long pow = 1;
        for(int i = size-1 ; i >= 1 ; i--)
        {
            pow = (pow * 26)%m;
        }

        unordered_map<unsigned long long , vector<unsigned long long>> mapp;
        unsigned long long key = 0;
        for(int i = 0 ; i < size ; i++)
        {
            key = ((key*26)%m + S[i]-'a')%m;
        }
        mapp[key] = vector<unsigned long long>(1,0);

        for(int i = size ; i < S.size(); i++)
        {
            key = (key - (( (S[i-size]-'a') * pow) % m)%m + m)%m;
            key = ((key * 26)%m + S[i]-'a')%m;
            if(mapp.find(key) == mapp.end())
            {
                mapp[key] = vector<unsigned long long> (1,i-size+1);
            }
            else
            {
                for(auto it : mapp[key])
                {
                    if(strcmp(S.substr(it,size).data(), S.substr(i-size+1, size).data()) == 0)
                   {
                        return S.substr(it,size);
                   }
                }
            }
        }
        return "";

    }

    string longestDupSubstring(string S)
    {
        int n = S.size();
        int low = 1, high = n;
        string ans = "";

        while(low <= high)
        {
            int mid = low + (high-low)/2;
            string out = support(mid, S);
            if(out=="")
            {
                high = mid -1;
            }
            else
            {
                ans = out;
                low = mid+1;
            }
        }
        return ans;
    }
};
