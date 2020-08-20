class Solution {
public:
    struct TrieNode
    {
        TrieNode* ch[26] ;
        int index = -1;
    };

    TrieNode* root;

    struct TrieNode* createNode()
    {
        TrieNode* nw = new TrieNode();
        for(int i = 0 ; i < 26 ; i++)
        {
            nw->ch[i] = NULL;
        }
        return nw;
    }

    bool isPal(string s)
    {
        if(s=="")return true;
        int n = s.size();
        int low = 0 , high = n-1;
        while(low<high)
        {
            if(s[low]==s[high])
            {
                low++;
                high--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }

    void dfs(vector<vector<int>> &out, TrieNode* ref, string s, int i)
    {
        if(!ref)return;
        if(ref->index!=-1 && ref->index!=i && isPal(s))
        {
          out.push_back({i,ref->index});
        }
        for(int j = 0 ; j < 26 ; j++)
        {
            if(ref->ch[j]!=NULL)
            {
                dfs(out, ref->ch[j], s+char(j+97), i);
            }
        }
    }

    vector<vector<int>> palindromePairs(vector<string>& words)
    {
        root = createNode();
        int ind = 0;
        for(auto &str : words)
        {
            TrieNode* ref = root;
            int n = str.size();
            for(int i = n-1 ; i >= 0 ; i--)
            {
                int indexing = str[i]-'a';
                if(!ref->ch[indexing])
                {
                    ref->ch[indexing] = createNode();
                }
                ref = ref->ch[indexing];
            }
            ref->index = ind++;
        }
        vector<vector<int>> output;
        int m = words.size();
        for(int i = 0 ; i < m ; i++)
        {
            TrieNode* ref = root;
            int n = words[i].size();
            bool flag = false;

            if(words[i]=="")
            {
                for(int k = 0 ; k < m ; k++)
                {
                    if(i!=k)
                    {
                        if(isPal(words[k]))
                        {
                            output.push_back({i,k});
                        }
                    }
                }
            }
            for(int j = 0 ; j < n ; j++)
            {
                if(ref->index!=-1 && ref->index!=i)
                {
                    if(isPal(words[i].substr(j)))
                    {
                        output.push_back({i,ref->index});
                    }
                }
                int indexing = words[i][j]-'a';
                if(ref->ch[indexing])
                {
                    ref = ref->ch[indexing];
                }
                else
                {
                     break;
                }

                if(j==n-1)
                {flag = true;}
            }
            if(flag)
            {
                dfs(output, ref, "",i);
            }
        }
        return output;
    }
};
