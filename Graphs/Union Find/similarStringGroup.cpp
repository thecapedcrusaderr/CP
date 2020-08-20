class Solution {
public:

    int out = 0;
    int diffStringPosition(string &a, string &b)
    {
        int l1 = a.size();
        int out = 0;
        for(int i = 0 ; i < l1 ; i++)
        {
            if(a[i]!=b[i])out++;
            if(out > 2)return out;
        }
        return out;
    }
    void join(vector<int> &parent, int a , int b)
    {
        int ap = find(parent,a);
        int bp = find(parent,b);
        if(ap!=bp)
        {
            parent[bp] = ap;
            out--;
        }
    }
    int find(vector<int> &parent, int num)
    {
        if(parent[num]==num)return num;
        int res = find(parent, parent[num]);
        parent[num] = res;
        return res;
    }

    int numSimilarGroups(vector<string>& A)
    {
        int n = A.size();
        out = n;
        vector<int> parent(n);
        for(int i = 0 ; i < n;  i++)
        {
            parent[i] = i;
        }

        for(int i = 0 ; i < n ; i++)
        {
            for(int j = i+1 ; j < n; j++)
            {
                int diff = diffStringPosition(A[i],A[j]);

                if(diff<=2)
                {
                    join(parent,i,j);
                }
            }
        }
        return out;
    }
};
