class Solution {
public:

    void join(vector<int> &rank, vector<int> &parent, int a, int b)
    {

        int aPar = find(a,parent);
        int bPar = find(b,parent);

        if(aPar==bPar)
        {
            rank[aPar]++;
        }
        else
        {
            if(rank[aPar] >= rank[bPar])
            {
                rank[aPar] += rank[bPar]+1;
                rank[bPar] = 1;
                parent[bPar] = aPar;
            }
            else
            {
                rank[bPar] += rank[aPar]+1;
                rank[aPar] = 1;
                parent[aPar] = bPar;
            }
        }
    }

    int find(int num , vector<int> &parent)
    {
        while(parent[num]!=num)
        {
            num = parent[num];
        }
        return num;
    }

    int removeStones(vector<vector<int>>& stones)
    {
        vector<int> rank(20001,0);
        vector<int> parent(20001);
        for(int i = 0 ; i <= 20000 ; i++)
        {
            parent[i] = i;
        }

        for(auto &s : stones)
        {
            int a = s[0];
            int b = s[1]+10000;
            join(rank, parent, a, b);
        }
        int ans = 0;
        for(int i = 0 ; i <= 20000 ; i++)
        {
            ans += max(0,rank[i]-1);
        }
        return ans;
    }
};
