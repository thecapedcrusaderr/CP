static int io_opt = []() {
    ios::sync_with_stdio(false);
    return 0;
}();

// Now i will do it with fucking 2 way bfs which i learnt and it's really amazing.
class Solution {
public:
    vector<vector<string>> out;
    // Now simple usual dfs to have out answer;

    void dfs(unordered_map<string, vector<string>> &graph, string &now ,string &end, vector<string> &temp)
    {
        temp.push_back(now);
        if(now==end)
        {
            out.push_back(temp);
            temp.pop_back();
            return;
        }

        for(auto &neb : graph[now])
        {
            dfs(graph,neb,end,temp);
        }
        temp.pop_back();
    }



    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList)
    {
        unordered_set<string> original(wordList.begin(),wordList.end());

        if(!original.count(endWord))return {};

        unordered_set<string> forward, backward;

        unordered_map<string, vector<string>> graph;

        forward.insert(beginWord);
        backward.insert(endWord);

        bool milan = false;
        bool reverse = false;

        // This basically is finding neighbors of the string using 2 way bfs, then we will apply dfs here.

        while(!forward.empty() && !backward.empty() && !milan)
        {
            if(forward.size() > backward.size())
            {
                reverse = !reverse;
                swap(forward, backward);
            }

            int n = forward.size();
            unordered_set<string> next;
            for(auto  i = forward.begin() ; i != forward.end() ; i++)
            {
                string orig = *i;

                string toExperiment = *i;

                int m = orig.size();
                for(int j = 0 ; j < m ; j++)
                {
                    char ret = toExperiment[j];
                    for(char c = 'a' ; c <= 'z' ; c++)
                    {
                        toExperiment[j] = c;
                        if(backward.count(toExperiment))
                        {
                            milan = true;
                        }

                        if(original.count(toExperiment) && !forward.count(toExperiment))
                        {
                            if(reverse)
                            {
                                graph[toExperiment].push_back(orig);
                            }
                            else
                            {
                                graph[orig].push_back(toExperiment);
                            }
                            next.insert(toExperiment);
                        }
                    }
                    toExperiment[j] = ret;
                }
            }
            for(auto it = forward.begin(); it!=forward.end(); it++)original.erase(*it);
            forward = next;
        }
        if(!milan)return {};

        vector<string> temp;
        dfs(graph,beginWord,endWord,temp);
        return out;
    }
};
