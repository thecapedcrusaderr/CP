/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    bool kmp(string &pattern, string &original)
    {

        // cout<<" pattern is "<<pattern<<endl;
        // cout<<" original is "<<original<<endl;

        int n = pattern.size(), m = original.size();
        if(n > m)return false;
        vector<int> support(n, 0);
        int i = 0, j = 1;
        while(j < n)
        {
            if(pattern[i]==pattern[j])
            {
                support[j] = i+1;
                i++;
                j++;
            }
            else
            {
                if(i > 0)
                {
                    i = support[i-1];
                }
                else
                {
                    j++;
                }
            }
        }

        for(int k = 0 , m_pos = 0 ; k < m ; )
        {
            if(pattern[m_pos]==original[k])
            {
                m_pos++;
                k++;
                if(m_pos==n)return true;
            }
            else
            {
                if(m_pos > 0)
                {
                    m_pos = support[m_pos-1];
                }
                else
                {
                    k++;
                }
            }
        }
        return false;
    }

    void infix(TreeNode* ref , string &str)
    {
        if(!ref)
        {
            str+="N";
            return;
        }
        infix(ref->left, str);
        str+=to_string(ref->val);
        infix(ref->right, str);
    }

    void prefix(TreeNode* ref, string &str)
    {
        if(!ref)
        {
            str+="N";
            return;
        }

        str += to_string(ref->val);
        prefix(ref->left, str);
        prefix(ref->right, str);
    }

    bool isSubtree(TreeNode* s, TreeNode* t)
    {
        if(!s && !t)return true;
        if(!s)return false;
        if(!t)return false;

        string t_pre = "", s_pre = "", t_in = "", s_in = "";

        prefix(s , s_pre);
        prefix(t , t_pre);
        infix(s, s_in);
        infix(t, t_in);

        return kmp(t_pre, s_pre) && kmp(t_in, s_in);
    }
};
