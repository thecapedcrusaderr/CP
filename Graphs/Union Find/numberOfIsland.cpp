class Solution {
public:

    void join(vector<int> &parent, vector<int> &rank, int num1, int num2)
    {
        int a = find(parent,num1);
        int b = find(parent,num2);

        if(a!=b)
        {
            if(rank[a] >= rank[b])
            {
                parent[b] = a;
                rank[a] += rank[b];
            }
            else
            {
                parent[a] = b;
                rank[b] += rank[a];
            }
        }
    }

    int find(vector<int> &parent, int num)
    {
        while(parent[num]!=num)
        {
            num = parent[num];
        }
        return num;
    }

    int numIslands(vector<vector<char>>& grid)
    {
        int m = grid.size();
        if(m==0)return 0;
        int n = grid[0].size();
        if(n==0)return 0;

        vector<int> parent(m*n);
        vector<int> rank(m*n,1);

        for(int i = 0 ; i < m ; i++)
        {
            for(int j = 0 ; j < n; j++)
            {
                if(grid[i][j]=='1')
                {
                    int num = n*i + j;
                    parent[num] = num;
                }
            }
        }

        for(int j = 1 ; j < n; j++)
        {
            if(grid[0][j]=='1' && grid[0][j-1]=='1')
            {
                int a = find(parent,j-1);
                parent[j] = a;
                rank[a]++;
            }
        }

        for(int i = 1 ; i < m ; i++)
        {
            for(int j = 0 ; j < n; j++)
            {
                if(grid[i][j]=='1')
                {
                    if(j==0)
                    {
                        if(grid[i-1][j]=='1')
                        {
                            int num1 = ((i-1) * n + j);
                            int num2 = i*n + j;
                            int a = find(parent,num1);
                            parent[num2] = a;
                            rank[a]++;
                        }
                    }
                    else
                    {
                        if(grid[i-1][j]=='1' && grid[i][j-1]=='1')
                        {
                            int num1 = ((i-1) * n + j);
                            int num2 = i*n + j-1;
                            int num3 = num2+1;
                            join(parent,rank,num1,num2);
                            parent[num3] = parent[num1];
                            rank[parent[num3]]++;
                        }
                        else if(grid[i-1][j]=='1')
                        {
                            int num1 = ((i-1) * n + j);
                            int num2 = i*n + j;
                            join(parent,rank,num1,num2);
                        }
                        else if(grid[i][j-1]=='1')
                        {
                            int num1 = ((i* n) + j-1);
                            int num2 = i*n + j;
                            join(parent,rank,num1,num2);
                        }
                    }
                }
            }
        }

        int ans = 0;

        unordered_map<int,int> cache;

        for(int i = 0 ; i < m ; i++)
        {
            for(int j = 0 ; j < n ;j++)
            {
                if(grid[i][j]=='1')
                {
                    int num = i*n + j;
                    int a = find(parent,num);

                    if(cache.count(a)==0)
                    {
                        ans++;
                        cache[a] = 1;
                    }
                }
            }
        }
        return ans;
    }
};
