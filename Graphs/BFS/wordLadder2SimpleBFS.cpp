// Kabhi bhi shortest path find krne me BFS hi lgana

class Solution {
public:

    vector<string> findNeighbors(string &word, unordered_set<string> &original)
    {
        int n = word.size();
        vector<string> out;

        for(int i = 0 ; i < n ; i++)
        {
            char c = word[i];
            for(char h = 'a' ; h <= 'z' ; h++)
            {
                word[i] = h;
                if(original.count(word))out.push_back(word);
            }
            word[i] = c;
        }
        return out;
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList)
    {
        unordered_set<string> wordOriginal(wordList.begin(),wordList.end());
        vector<vector<string>> out;
        if(!wordOriginal.count(endWord))return out;

        queue<vector<string>> curr;
        curr.push({beginWord});
        bool flag = false;
        wordOriginal.erase(beginWord);
        unordered_set<string> visit;


        while(!curr.empty())
        {
            int sz = curr.size();

            for(int i = 0 ; i < sz ; i++)
            {
                vector<string> here = curr.front();
                curr.pop();

                vector<string> neb = findNeighbors(here.back(), wordOriginal);

                for(int i = 0 ; i < neb.size() ; i++)
                {
                    vector<string> lelo(here.begin(),here.end());
                    lelo.push_back(neb[i]);
                    if(neb[i]==endWord)
                    {
                        flag = true;
                        out.push_back(lelo);
                    }
                    visit.insert(neb[i]);
                    curr.push(lelo);
                }
            }
            if(flag)break;
            for(auto it = visit.begin(); it!= visit.end(); it++)
            {
                wordOriginal.erase(*it);
            }
            visit.clear();
        }
        return out;
    }
};
