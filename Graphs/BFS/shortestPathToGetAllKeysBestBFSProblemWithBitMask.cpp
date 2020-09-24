// I had learnt this new thing, 3D visited arrray lena aur sbse main use, bit masking here which i couldn't think of earlier. Thank God i came across this question.

class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid)
    {
        int m = grid.size(), n = grid[0].size();
        int si = -1, sj = -1, totalLock = 0;

        for(int i = 0 ; i < m ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                if(grid[i][j]=='@')
                {
                    si = i, sj = j;
                    continue;
                }
                if(grid[i][j]=='.' || grid[i][j]=='#')continue;

                int ind = grid[i][j]-'A';
                if(ind > 25)ind-=32;
                totalLock = max(totalLock , ind+1);
            }
        }

        if(totalLock == 0)return 0;

        int sz = 1<<(totalLock+1);

        bool visited[m][n][sz];

        for(int i = 0 ; i < m ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                for(int k = 0 ; k < sz ; k++)visited[i][j][k] = false;
            }
        }

        int dirn[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

        int ans = 0;
        queue<vector<int>> q;
        q.push({si,sj,1});
        visited[si][sj][1] = true;

        while(!q.empty())
        {
            int k = q.size();
            for(int i = 0 ; i < k ; i++)
            {
                vector<int> h = q.front();
                if(h[2]==sz-1)return ans;
                q.pop();

                for(auto &d : dirn)
                {
                    int a = h[0]+d[0], b = h[1]+d[1];
                    if(a < 0 || a >= m || b < 0 || b>=n || grid[a][b]=='#' )continue;

                    if(grid[a][b]=='.' || grid[a][b]=='@')
                    {
                        if(visited[a][b][h[2]])continue;
                        visited[a][b][h[2]] = true;
                        q.push({a,b,h[2]});
                        continue;
                    }

                    int ind = grid[a][b]-'@';

                    if(ind > 26)
                    {
                        ind = ind-32;
                        int here = h[2] | 1<<ind;
                        if(!visited[a][b][here])
                        {
                            visited[a][b][here] = true;
                            q.push({a,b,here});
                        }
                    }
                    else
                    {
                        int here = 1<<ind & h[2];
                        if(here)
                        {
                            if(!visited[a][b][h[2]])
                            {
                                visited[a][b][h[2]] = true;
                                q.push({a,b,h[2]});
                            }
                        }
                        else
                        {
                            continue;
                        }
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};
