#include <iostream>
using namespace std;
// new branch about

// second commit
class TrieNode
{
public:
  char data;
  TrieNode *children[128];
  bool isTerminal;
  TrieNode(char ch)
  {
    data = ch;
    for (int i = 0; i < 128; i++)
    {
      children[i] = NULL;
    }
    isTerminal = false;
    // new commit after creating branch about
  }
};
class Trie
{
public:
  TrieNode *root;
  Trie()
  {
    root = new TrieNode('\0');
  }

  void insertUtil(TrieNode *root, string word)
  {
    // base case
    if (word.length() == 0)
    {
      root->isTerminal = true; // it will be last character
      return;
    }
    int index = word[0]; // assume all char are capitals
    TrieNode *child;
    // present
    if (root->children[index] != NULL)
    {
      child = root->children[index];
    }
    // absent
    else
    {
      child = new TrieNode(word[0]); // new node create..then insert into the array
      root->children[index] = child;
    }
    insertUtil(child, word.substr(1));
  }

  void insertWord(string word)
  {
    insertUtil(root, word);
  }

  bool searchUtil(TrieNode *root, string word)
  {
    if (word.length() == 0)
    {
      return root->isTerminal;
    }
    int index = word[0];
    TrieNode *child;
    if (root->children[index] != NULL)
    {
      child = root->children[index];
    }
    else
    {
      return false;
    }
    return searchUtil(child, word.substr(1));
  }

  bool searchWord(string word)
  {
    return searchUtil(root, word);
  }
};
int main()
{
  Trie *t = new Trie();

  t->insertWord("abcd");
  t->insertWord("do");
  t->insertWord("time");

  cout
      << "present or not " << t->searchWord("tim ") << endl;

  return 0;
}