// Although this appears to be an easy question, but i find it worth doing it. I don't know why this question is in easy category.

// Now, that i have got zist of the KMP Algorithm i would try to do this question in O(m+n) complexity.

class Solution {
public:

    int strStr(string haystack, string needle)
    {
        int m = haystack.size(), n = needle.size();
        if(!n)return 0;

        vector<int> support(n,0);

        int i = 1 , j = 0;
        while(i < n)
        {
            if(needle[i]==needle[j])
            {
                support[i] = j+1;
                i++;
                j++;
            }
            else
            {
                if( j > 0)
                {
                    j = support[j-1];
                }
                else
                {
                    i++;
                }
            }
        }

        // Now, that we have matching we will go with the index part.

        for(int i = 0 , m_pos = 0 ;  i < m ; )
        {
            if(haystack[i]==needle[m_pos])
            {
                if(m_pos==n-1)
                {
                    return (i-n+1);
                }
                else
                {
                    i++;
                    m_pos++;
                }
            }
            else
            {
                if(m_pos==0)
                {
                    i++;
                }
                else
                {
                    m_pos = support[m_pos-1];
                }
            }
        }
        return -1;
    }
};
