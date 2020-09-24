// This is a question of Strange Printer ||
class Solution {
public:

    bool topoLogicalWithDfs(vector<unordered_set<int>> &graph, vector<int> &visited, int num)
    {
        if(visited[num]==-1)return false;
        if(visited[num]==1)return true;

        visited[num] = -1;

        for(auto it = graph[num].begin(); it != graph[num].end(); it++)
        {
            if(!topoLogicalWithDfs(graph, visited, *it))return false;
        }
        visited[num] = 1;

        return true;
    }

    bool isPrintable(vector<vector<int>>& targetGrid)
    {
        int m = targetGrid.size(), n = targetGrid[0].size();

        vector<int> right(61,INT_MIN), left(61,INT_MAX), upper(61, INT_MAX), lower(61,INT_MIN);

        for(int i = 0 ; i < m ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                int num = targetGrid[i][j];
                right[num] = max(right[num], j);
                left[num]  = min(left[num], j);
                upper[num] = min(upper[num], i);
                lower[num] = max(lower[num], i);

            // cout<<" for num = "<<num<<" , "<<left[num]<<" "<<right[num]<<" "<<upper[num]<<" "<<lower[num]<<endl;
            }
        }

        // cout<<" printing left right upper lower here "<<endl;
        // for(int i = 1 ; i <= 3 ; i++)
        // {
        //     cout<<" for i = "<<i<<" , "<<left[i]<<" "<<right[i]<<" "<<upper[i]<<" "<<lower[i]<<endl;
        // }


        vector<unordered_set<int>> graph(61);

        for(int i =1 ; i <= 60; i++)
        {
            int l = left[i], r = right[i], u = upper[i], d = lower[i];
            if(l==INT_MAX)continue;

            for(int k = u ; k <= d ; k++)
            {
                for(int j = l; j <= r; j++)
                {
                    if(targetGrid[k][j]!=i)
                    {
                        graph[i].insert(targetGrid[k][j]);
                    }
                }
            }
        }

//         cout<<" printing graph here "<<endl;
//         for(int i =1 ; i <= 3 ; i++)
//         {
//             cout<<" i = "<<i<<endl;
//             for(auto j = graph[i].begin(); j != graph[i].end(); j++)
//             {
//                 cout<<*j<<" ";
//             }
//             cout<<endl;
//         }

        vector<int> visited(61,0);

        for(int i = 1 ; i <= 60; i++)
        {
            if(!topoLogicalWithDfs(graph, visited, i))return false;
        }
        return true;
    }
};
