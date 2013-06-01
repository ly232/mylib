#include <iostream>
#include "hashtable.h"
int main(int argc, char** argv){
  HashTable<std::string> ht;
  std::size_t cap = ht.get_capacity();
  std::cout<<"ht size = "<<cap<<std::endl;
  if (ht.get("ly232", NULL)==FAIL)
    std::cout<<"no item with key 'ly232'"<<std::endl;
  if (ht.put("ly232","Lin Yang")==FAIL)
    std::cout<<"ERROR: failed to insert record with key 'ly232'"<<std::endl;
  std::string name = "";
  if (ht.get("ly232",&name)==SUCCESS)
    std::cout<<"ht.get(ly232)="<<name<<std::endl;
  std::string holder;
  if (ht.remove("ly232", &holder)==SUCCESS)
    std::cout<<"deleted value: "<<holder<<std::endl;
  if (ht.get("ly232", NULL)==FAIL)
    std::cout<<"no item with key 'ly232'"<<std::endl;
  
  return 0;
}

