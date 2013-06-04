#ifndef _queue_h
#define _queue_h
#include "linkedlist.h"
template <typename T>
class queue{
 public:
  queue(){};
  ~queue(){};
  STATUS push(const T& item){
    return data.append(&item);
  };
  //client is responsible to free holder
  STATUS pop(T*& holder){
    return data.pop_front(holder);
  }
 private:
  linkedlist<T> data;
};
#endif
