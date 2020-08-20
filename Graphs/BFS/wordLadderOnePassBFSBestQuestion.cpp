// One of the best question of BFS i came across.

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList)
    {
        unordered_set<string> ref(wordList.begin(),wordList.end());

        queue<string> curr;
        curr.push(beginWord);
        int ans = 1;

        while(!curr.empty())
        {
            int n = curr.size();
            for(int i = 0 ; i < n ; i++)
            {
                string fr = curr.front();
                curr.pop();
                if(endWord==fr)
                {
                    return ans;
                }
                ref.erase(fr);
                for(int j = 0 ; j < fr.size(); j++)
                {
                    char c = fr[j];
                    for(int k = 0 ; k < 26 ; k++)
                    {
                        fr[j] = 'a'+ k;
                        if(ref.find(fr)!=ref.end())
                        {
                            curr.push(fr)
;                        }
                    }
                    fr[j] = c;
                }
            }
            ans++;
        }
        return 0;
    }
};
