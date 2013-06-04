#ifndef _stack_h
#define _stack_h
#include "linkedlist.h"
template <typename T>
class stack{
 public:
  stack(){};
  ~stack(){};
  STATUS push(const T& item){
    return data.prepend(&item);
  };
  //client is responsible to free holder
  STATUS pop(T*& holder){
    return data.pop_front(holder);
  }
 private:
  linkedlist<T> data;
};
#endif
