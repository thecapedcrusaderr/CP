#include<bits/stdc++.h>
using namespace std;

struct TrieNode
{
  TrieNode *children[26];
  bool isEndOfWord;
} ;

struct TrieNode *createNode()
{
  struct TrieNode *newNode = new TrieNode;
  newNode->isEndOfWord = false;

  for(int i = 0 ; i < 26 ; i++)
  {
    newNode->children[i] = NULL;
  }
  return newNode;
}

void insert(struct TrieNode *root, string key)
{
  struct TrieNode *pointer = root;
  for(int i = 0 ; i < key.size(); i++)
  {
    int index = key[i]-'a';
    if(!pointer->children[index])
    {
      pointer->children[index] = createNode();
    }
    pointer = pointer->children[index];
  }
  pointer->isEndOfWord = true;
}

bool search(struct TrieNode *root, string key)
{
  struct TrieNode *pointer = root;
  for(int i = 0 ; i < key.size(); i++)
  {
    int index = key[i]-'a';
    if(pointer->children[index]==NULL)
    {
      return false;
    }
    pointer = pointer->children[index];
  }
  if(pointer->isEndOfWord == true)
  {
    return true;
  }
}

bool isEmpty(struct TrieNode *root)
{
  for(int i = 0 ; i < 26; i++)
  {
    if(root->children[i]!=NULL)return true;
  }
  return false;
}

struct TrieNode *deletion(struct TrieNode *root, string key, int depth)
{
   if(!root)return NULL;
   if(key.size()==depth)
   {
     if(root->isEndOfWord)
     {
       root->isEndOfWord = false;
     }
     if(isEmpty(root))
     {
       delete(root);
       root = NULL;
     }
     return root;
   }
   int index = key[depth]-'a';
   root->children[index] = deletion(root->children[index], key, 1+depth);

   if(isEmpty(root) && root->isEndOfWord == false)
   {
     delete(root);
     root = NULL;
   }
   return root;
}

int main()
{
  string input[5] = {"helloworld","hi","bye", "the","thena"};
  struct TrieNode *root = createNode();
  struct TrieNode *pointer = root;
  for(int i = 0 ; i < 5 ; i++)
  {
    insert(pointer, input[i]);
  }
  // Now will search the word helloworld and Hey there
  cout<<"Does string helloworld exist in the tree? "<<search(pointer,"helloworld")<<endl;;
  cout<<"Does string Hey There exist in the tree? "<<search(pointer,"Hey There")<<endl;
  deletion(root,"the",0)? cout<<"String the Deleted "<<endl : cout<<"String the is still present"<<endl;
  cout<<"Seaching word the after deleting it. Does it still exist "<<search(pointer,"the")<<endl;
}
