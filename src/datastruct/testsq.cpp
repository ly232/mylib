//test stack and heap
#include "stack.h"
#include "queue.h"
#include <iostream>
int main(int argc, char** argv){
  stack<int> si = stack<int>();
  queue<int> qi = queue<int>();
  for (int i=1; i<=10; i++){
    si.push(i);
    qi.push(i);
  }
  for (int i=1; i<=10; i++){
    int* holder = NULL;
    STATUS retval = si.pop(holder);
    std::cout<<"si popped "<<*holder<<std::endl;
    delete holder;
    retval = qi.pop(holder);
    std::cout<<"qi popped "<<*holder<<std::endl;
    delete holder;
  }
  
  return 0;
}
