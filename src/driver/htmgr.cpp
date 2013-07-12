//hash table manager
#ifndef _htmgr_h
#define _htmgr_h
#include "hashtable.h"
template <typename T>
class htmgr{
public:
  htmgr():ht_arr(NULL){};
private:
  hashtable<T>* ht_arr;
};
#endif

