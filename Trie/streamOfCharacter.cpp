// This is one of the best question of Trie i have come across, reverse dictionary lene ka hai
class StreamChecker {
public:

    struct Trie
    {
        Trie *ch[26];
        bool isEndHere = false;
    };

    Trie *root;
    string str;

    bool ifExist(string &word)
    {
        Trie *here = root;
        int n = word.size();
        for(int i= n-1 ; i >= 0 ; i--)
        {
            int index = word[i]-'a';
            if(!here->ch[index])return false;
            here = here->ch[index];
            if(here->isEndHere)return true;
        }
        return false;
    }

    void createTree(vector<string> &words)
    {
        str = "";
        for(auto &w : words)
        {
            Trie *here = root;
            int n = w.size();
            for(int i = n-1 ; i >= 0 ; i--)
            {
                int index = w[i]-'a';
                if(!(here->ch[index]))
                {
                    Trie *nw = new Trie();
                    for(int j = 0 ; j < 26; j++)
                    {
                        nw->ch[j] = NULL;
                    }
                    here->ch[index] = nw;
                }
                here = here->ch[index];
            }
            here->isEndHere = true;
        }
    }

    StreamChecker(vector<string>& words)
    {
        root = new Trie();
        for(int i = 0 ; i < 26; i++)
        {
            root->ch[i] = NULL;
        }
        createTree(words);
    }

    bool query(char letter)
    {
        int charInd = letter - 'a';
        str += letter;
        // if(str.size() > 2000)str = str.substr(0,2000);
        if(ifExist(str))return true;
        return false;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
