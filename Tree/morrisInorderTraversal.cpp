#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
}

vector<int> inorderTraversal(TreeNode* root)
{
  vector<int> output;
  TreeNode* curr, pre;
  curr = root;

  while(curr!=NULL)
  {
    if(curr->left == NULL)
    {
      output.push_back(curr->val);
      curr = curr->right;
    }
    else
    {
      pre = curr->left;
      while(pre->right != NULL && pre->right!=curr)
      {
        pre = pre->right;
      }
      if(pre->right == NULL)
      {
        pre->right = curr;
        curr = curr->left;
      }
      else
      {
        pre->right = NULL;
        output.push_back(curr->val);
        curr = curr->right;
      }
    }
  }
  return output;
}
