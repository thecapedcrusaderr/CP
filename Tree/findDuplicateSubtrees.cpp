struct TreeNode
 {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
class Solution {
public:
    vector<TreeNode*> out;

    string support(TreeNode* root, unordered_map<string,int> &mapp)
    {
        if(root==NULL)return "";
        string here = to_string(root->val)+","+support(root->left, mapp)+","+support(root->right, mapp);
        if(++mapp[here]==2)out.push_back(root);
        return here;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root)
    {
        unordered_map<string,int> mapp;
        string s  = support(root, mapp);
        return out;
    }

};
