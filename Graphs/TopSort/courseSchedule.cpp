class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);
        for(auto p : prerequisites)
        {
            int a = p[0], b = p[1];
            graph[b].push_back(a);
            indegree[a]++;
        }
        vector<bool> visited(numCourses, false);
        queue<int> q;

        for(int i = 0 ; i < numCourses; i++)
        {
            if(indegree[i]==0)q.push(i);
        }
        while(!q.empty())
        {
            int deg = q.front();
            numCourses--;
            visited[deg] = true;
            q.pop();
            for(auto next : graph[deg])
            {
                if(!visited[next])
                {
                    if(--indegree[next]==0)q.push(next);
                }
            }
        }
        return numCourses==0 ? true : false;
    }
};
