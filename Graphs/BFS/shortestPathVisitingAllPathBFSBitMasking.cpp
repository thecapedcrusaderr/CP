// Ye bhi bitmasking ka question hai, socho aur kro.
class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph)
    {
        int m = graph.size();
        int sz = 1<<m;

        int ans = INT_MAX;

        for(int j = 0 ; j < m ; j++)
        {
            vector<vector<bool>> visited(m , vector<bool> (sz,false));
            queue<pair<int,int>> q;
            q.push({j,1<<j});
            visited[j][1<<j] = true;
            bool huakya = false;
            int temp = 0;

            while(!q.empty())
            {
                if(huakya)break;
                int k = q.size();
                for(int i = 0 ; i < k ; i++)
                {
                    pair<int,int> here = q.front();
                    q.pop();
                    int a = here.first, b = here.second;
                    if(b==sz-1)
                    {
                        ans = min(ans, temp);
                        huakya = true;
                        break;
                    }

                    for(auto &nex : graph[a])
                    {
                        int bitVal = b | 1<<nex;
                        if(!visited[nex][bitVal])
                        {
                            visited[nex][bitVal] = true;
                            q.push({nex, bitVal});
                        }
                    }
                }
                temp++;
            }
            // cout<<" ans starting with j = "<<j<<" is "<<ans<<endl;
        }

        return ans;
    }
};
