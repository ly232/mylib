//bst.h
#ifndef _bst_h
#define _bst_h
#include "common.h"
class bst
{
public:
  bst():root(NULL)
  {
    
  };
  ~bst()
  {

  };
  const bst& operator=(const bst& rhs)
  {
    return rhs;
  };
  bst(const bst&)
  {

  };
  int height()
  {
    return -1;
  };

  template <typename T>
  STATUS insert(const std::string& key, const T& value)
  {
    return FAIL;
  };
  
  STATUS remove(const std::string& key)
  {
    return FAIL;
  };
private:

  template <typename T>
  struct node
  {
    std::string key;
    T value;
    node* left, right;
  };
  
  template <typename T>
  struct node<T>* root;
};
#endif
