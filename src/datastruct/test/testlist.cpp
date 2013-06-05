#include <iostream>
#include <string>
#include <sstream>
#include "linkedlist.h"
using namespace std;
int main(){
  cout<<"linked list test..."<<endl;
  STATUS result = SUCCESS;
  linkedlist<int>* intlist = new linkedlist<int>;
  linkedlist<string>* strlist = new linkedlist<string>;
  for (int i=0; i<10; i++){
    result = (STATUS) (result * intlist->prepend(&i));
    result = (STATUS) (result * intlist->append(&i));
    
    stringstream ss;
    ss<<i;
    string s;
    ss>>s;
    strlist->append(&s);
    strlist->prepend(&s);
    
  }
  for (int i=0; i<10; i++){
    int* holder;
    result = (STATUS) (result * intlist->pop_front(holder));
    cout<<"popped "<<*holder<<endl;;
    if (result = SUCCESS) delete holder;
    result = (STATUS) (result * intlist->pop_back(holder));
    cout<<"popped "<<*holder<<endl;
    if (result = SUCCESS) delete holder;
  }
    int* holder;
    STATUS shouldfail = intlist->pop_front(holder);
    cout<<"sholdfail = "<<shouldfail<<endl;;
    
  

  delete intlist;
  delete strlist;
  if (result==SUCCESS)
    cout<<"all tests passed!"<<endl;
  return 0;
}
