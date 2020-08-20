// Here i come with amazing 2 End bfs solution

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList)
    {
        unordered_set<string> original(wordList.begin(),wordList.end());

        if(!original.count(endWord))return 0;

        unordered_set<string> forward;
        forward.insert(beginWord);
        unordered_set<string> backward;
        backward.insert(endWord);
        int ans = 0;

        while(!forward.empty() && !backward.empty())
        {
            ans++;
            unordered_set<string> next;
            if(forward.size() > backward.size())
            {
                swap(forward, backward);
            }
            for(auto &s : forward)
            {
                original.erase(s);
            }
            for(auto &s : backward)
            {
                original.erase(s);
            }

            int n = beginWord.size();

            for(auto str : forward)
            {
                for(int i = 0; i < n ; i++)
                {
                    char c = str[i];
                    for(int j = 0 ; j < 26 ; j++)
                    {
                        str[i] = char(97+j);
                        if(backward.count(str))return ans+1;
                        if(original.count(str))
                        {
                            next.insert(str);
                        }
                    }
                    str[i] = c;
                }
            }
            swap(next, forward);
        }

        return 0;

    }
};
