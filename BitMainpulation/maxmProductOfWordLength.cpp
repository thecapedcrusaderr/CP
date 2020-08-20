class Solution {
public:
    int maxProduct(vector<string>& words)
    {
        int n = words.size();
        vector<int> hashValue(n,0);

        for(int i = 0 ; i < n; i++)
        {
            int m = words[i].size();
            for(int j = 0 ; j < m ; j++)
            {
                hashValue[i] |= 1<<(words[i][j]-'a');
            }
        }

        int ans = 0;
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = i+1 ; j < n ; j++)
            {
                if(!(hashValue[i]&hashValue[j]))
                {
                    int k = words[i].size()*words[j].size();
                    ans = max(ans,k);
                }
            }
        }
        return ans;
    }
};
