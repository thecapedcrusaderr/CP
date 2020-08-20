class Solution {
public:
    bool dfs(int i, vector<vector<int>> &graph, vector<int> &status)
    {
        if(status[i]==-1)return false;
        if(status[i]==1)return true;
        status[i] = -1;
        for(auto deg : graph[i])
        {
            if(!dfs(deg,graph,status))return false;
        }
        status[i] = 1;
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);
        for(auto p : prerequisites)
        {
            int a = p[0],  b = p[1];
            graph[a].push_back(b);
        }
        vector<int> status(numCourses,0);
        for(int i = 0 ; i < numCourses; i++)
        {
            if(!dfs(i,graph,status))return false;
        }
        return true;
    }
};
