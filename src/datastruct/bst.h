//bst.h
#ifndef _bst_h
#define _bst_h
#include "common.h"
#define max(a,b) (a>b)?a:b
typedef struct node node;
template <typename T>
class bst
{
public:
  bst():root(NULL)
  {
    
  };
  ~bst()
  {
    
  };
  void print_tree()
  {
    print_tree_helper(root, 0);
  }
  int height()
  {
    return height_helper(root);
  };

  STATUS insert(const std::string& key, const T& value)
  {
    if (key.size()==0)
      return FAIL;
    insert_helper(root, key.c_str(), value);
    return SUCCESS;
  };
  
  STATUS remove(const std::string& key)
  {
    return FAIL;
  };
private:
  struct node
  {
    std::string key;
    T value;
    node* left;
    node* right;
  };
  node* root;

  void print_tree_helper(node* n, int level)
  {
    std::string tab = "";
    if (n==NULL)
      return;
    for (int i=0; i<level; i++)
    {
      tab += "\t";
    }
    std::cout<<tab<<n->key<<":"<<n->value<<std::endl;
    print_tree_helper(n->left, level+1);
    print_tree_helper(n->right, level+1);
  }

  void insert_helper(node*& n, const char* key, const T& value)
  {
    int compval;
    if (n==NULL)
    {
      n = new node;
      n->key = std::string(key);
      n->value = value;
      n->left = NULL;
      n->right = NULL;
      return;
    }
    compval = strcmp((n->key).c_str(), key);
    if (compval==0) //overwrite existing kv pair
    {
      n->value = value;
      return;
    }
    else if (compval > 0)
      insert_helper(n->left, key, value);
    else
      insert_helper(n->right, key, value);    
  }

  int height_helper(node* n)
  {
    if (!n)
      return 0;
    return 1+max(height_helper(n->left), height_helper(n->right));
  }

  const bst& operator=(const bst& rhs)
  {

  };
  bst(const bst&)
  {

  };

};
#endif
