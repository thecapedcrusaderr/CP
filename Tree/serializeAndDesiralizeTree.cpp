// What i learnt from this is, use of some character for checkpoiont we don't need to have equal number of nodes at every level. Even less can suffice.
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root)
    {
        if(!root) return "#";

        return to_string(root->val)+","+serialize(root->left)+","+serialize(root->right);
    }

    int findValue(string &data)
    {
        int pos = data.find(",");
        int val = stoi(data.substr(0,pos));
        data = data.substr(pos+1);
        return val;
    }

    TreeNode* deserialSupport(string &data)
    {
        if(data[0]=='#')
        {
            if(data.size() > 1)data = data.substr(2);
            return NULL;
        }
        else
        {
            TreeNode *node = new TreeNode(findValue(data));
            node->left = deserialSupport(data);
            node->right = deserialSupport(data);
            return node;
        }
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data)
    {
        return deserialSupport(data);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
// Decodes your encoded data to tree.
