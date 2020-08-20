class Solution {
public:
    struct TrieNode
    {
        TrieNode* left = NULL;
        TrieNode* right = NULL ;
    };

    TrieNode* root;

    struct TrieNode* createNode()
    {
        TrieNode* nw = new TrieNode();
        return nw;
    }

    void createTree(TrieNode* ref, int num)
    {
        for(int i = 30; i>=0; i--)
        {
            int bit = num>>i & 1;
            if(bit==0)
            {
                if(!ref->left)
                {
                    ref->left = createNode();
                }
                ref = ref->left;
            }
            else
            {
                if(!ref->right)
                {
                    ref->right = createNode();
                }
                ref = ref->right;
            }
        }
    }


    int findMaximumXOR(vector<int>& nums)
    {
        root = createNode();
        for(auto& num : nums)
        {
            createTree(root,num);
        }

        int maxXOR = INT_MIN;
        for(auto &num : nums)
        {
            TrieNode* ref = root;
            int currXor = 0;
            for(int i = 30; i>=0; i--)
            {
                int bit = num>>i & 1;
                if(bit==0)
                {
                    if(ref->right)
                    {
                        currXor+= pow(2,i);
                        ref = ref->right;
                    }
                    else
                    {
                        ref = ref->left;
                    }
                }
                else
                {
                    if(ref->left)
                    {
                        currXor += pow(2,i);
                        ref = ref->left;
                    }
                    else
                    {
                        ref = ref->right;
                    }
                }
            }
          maxXOR = max(maxXOR, currXor);
        }
        return maxXOR;
    }
};
