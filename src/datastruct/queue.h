#ifndef _queue_h
#define _queue_h
#include "linkedlist.h"
template <typename T>
class queue{
 public:
  queue():size(0){};
  ~queue(){};
  STATUS push(T& item){
    size++;
    return data.append(&item);
  };
  //client is responsible to free holder
  STATUS pop(T*& holder = NULL){
    size--;
    return data.pop_front(holder);
  }
 private:
  linkedlist<T> data;
  std::size_t size;
};
#endif
