class WordDictionary {
public:
    /** Initialize your data structure here. */

    struct TrieNode
    {
        TrieNode* ch[26];
        bool isEndHere;
    };

    TrieNode *root;

    struct TrieNode* createNode()
    {
        TrieNode* nw = new TrieNode();
        for(int i = 0 ; i < 26 ; i++)
        {
            nw->ch[i]=NULL;
        }
        nw->isEndHere = false;
        return nw;
    }

    WordDictionary()
    {
        root = createNode();
    }

    /** Adds a word into the data structure. */
    void addWord(string word)
    {
        TrieNode* ref = root;
        int n = word.size();
        for(int i = 0 ; i < n ; i++)
        {
            int index = word[i]-'a';
            if(ref->ch[index]==NULL)
            {
                ref->ch[index] =  createNode();
            }
            ref = ref->ch[index];
        }
        ref->isEndHere = true;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */

    bool dfs(string word, TrieNode* ref, int i)
    {
        if(ref==NULL)return false;
        int n = word.size();
        if(i==0 && i==n )
        {
            if(ref->isEndHere)return true;
            else return false;
        }
        else if(i!=0)
        {
            if(i==n)return true;
        }


        if(word[i]=='.')
        {
            // cout<<"isme to aaya hi hoga "<<endl;

            if(i==n-1)
            {
                for(int j = 0 ; j < 26; j++)
                {
                    if(ref->ch[j] && ref->ch[j]->isEndHere)return true;
                }
                return false;
            }

            bool ot = false;
            for(int j = 0 ; j < 26 ; j++)
            {
                ot = ot || dfs(word, ref->ch[j], i+1);
            }
            return ot;
        }
        else
        {
            // cout<<"agar iske andar aa rha hai to i ki kya value hai "<<i<<endl;
            int index = word[i]-'a';
            if(ref->ch[index]==NULL)
            {
                return false;
            }
            else
            {
                if(i==n-1)
                {
                    // cout<<"iske andar to ni aa skta hai i guess let's check "<<endl;
                    if(ref->ch[index]->isEndHere)
                    {return true;}
                    else
                    {
                        return false;
                    }
                }
                // cout<<"index jo bheja jaa rha hai "<<index<<endl;
                return dfs(word, ref->ch[index],i+1);
            }
        }
    }

    bool search(string word)
    {
        bool out = dfs(word, root, 0);
        return out;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
