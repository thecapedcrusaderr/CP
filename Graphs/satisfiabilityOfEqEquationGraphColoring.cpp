// ios_base::sync_with_stdio(false);
// cin.tie(NULL);
// cout.tie(NULL);

class Solution {
public:



    void graphColoring(vector<vector<int>> &graph, vector<int> &color,vector<bool> &visited, int ch, int col )
    {
        visited[ch] = true;
        color[ch] = col;
        for(auto num : graph[ch])
        {
            if(!visited[num])
            {
                graphColoring(graph,color,visited,num,col);
            }
        }
    }

    bool equationsPossible(vector<string>& equations)
    {
        vector<bool> visited(26,false);
        vector<vector<int>> graph(26);
        vector<int> color(26);

        for(auto &str : equations)
        {
            if(str[1]=='=')
            {
                int l = str[0]-'a', r = str[3]-'a';
                graph[l].push_back(r);
                graph[r].push_back(l);
            }
        }

        int c = 0;

        for(int i = 0 ; i < 26 ; i++)
        {
            if(!visited[i])
            {
                graphColoring(graph,color,visited,i,c++);
            }
        }

        for(auto &str : equations)
        {
            if(str[1]=='!')
            {
                int l = str[0]-'a', r = str[3]-'a';
                if(color[l]==color[r])return false;
            }
        }

        return true;
    }
};
