#ifndef _stack_h
#define _stack_h
#include "linkedlist.h"
template <typename T>
class stack{
 public:
  stack():size(0){};
  ~stack(){};
  STATUS push(T& item){
    size++;
    return data.prepend(&item);
  };
  //client is responsible to free holder
  STATUS pop(T*& holder = NULL){
    size--;
    return data.pop_front(holder);
  };
  bool isEmpty(){
    return (size==0);
  };
 private:
  linkedlist<T> data;
  std::size_t size;
};
#endif
