#include <iostream>
#include "hashtable.h"

using namespace std;
enum OPTION{
  QUIT = 0,
  CREATE,
  DELETE,
  PUT,
  GET,
  REMOVE,
  UPDATE,
  LIST
};
int main(int argc, char** argv){
  //htmgr hm
  HashTable<string> ht(1);
  while (true){
    int option = 0;
    string key, value;
    cout<<"select an option, or enter 0 to quit:"<<endl;
    //cout<<"1. create hashtable"<<endl;
    //cout<<"2. delete hashtable"<<endl;
    cout<<"3. put"<<endl;
    cout<<"4. get"<<endl;
    cout<<"5. remove"<<endl;
    cout<<"6. update"<<endl;
    cout<<"7. list all existing hashtables"<<endl;
    cout<<"enter option: ";
    cin>>option;
    switch(option){
      case QUIT:
        return 0;
      case CREATE:
        break;
      case DELETE:
        break;
      case PUT:
        cout<<"key: ";
        cin>>key;
        cout<<"value: ";
        cin>>value;
        if (ht.put(key, value)==SUCCESS)
          cout<<"SUCCESS"<<endl;
        else
          cout<<"FAIL"<<endl;
        break;
      case GET:
        break;
      case REMOVE:
        break;
      case UPDATE:
        break;
      case LIST:
        break;
      default:
        break;
    }
  }
  return 0;
}
/*
int main(int argc, char** argv){
  HashTable<std::string> ht(1);
  std::size_t cap = ht.get_capacity();
  std::size_t sz = ht.get_size();
  std::cout<<"ht capacity = "<<cap<<std::endl;
  std::cout<<"ht size = "<<sz<<std::endl;
  if (ht.get("ly232", NULL)==FAIL)
    std::cout<<"no item with key 'ly232'"<<std::endl;
  if (ht.put("ly232","Lin Yang")==FAIL)
    std::cout<<"ERROR: failed to insert record with key 'ly232'"<<std::endl;
  if (ht.put("ly232","Lin Yang")==FAIL)
    std::cout<<"ERROR: failed to insert record with key 'ly232'"<<std::endl;
  if (ht.put("cw597","Chen Wang")==FAIL)
    std::cout<<"ERROR: failed to insert record with key 'cw597'"<<std::endl;
  std::string name = "";
  if (ht.get("ly232",&name)==SUCCESS)
    std::cout<<"ht.get(ly232)="<<name<<std::endl;
  std::string holder;
  if (ht.remove("ly232", &holder)==SUCCESS)
    std::cout<<"deleted value: "<<holder<<std::endl;
  if (ht.get("ly232", NULL)==FAIL)
    std::cout<<"no item with key 'ly232'"<<std::endl;
  if (ht.get("cw597",&name)==SUCCESS)
    std::cout<<"ht.get(cw597)="<<name<<std::endl;
  if (ht.remove("cw597", &holder)==SUCCESS)
    std::cout<<"deleted value: "<<holder<<std::endl;
  if (ht.get("cw597", NULL)==FAIL)
    std::cout<<"no item with key 'cw597'"<<std::endl;
  cap = ht.get_capacity();
  sz = ht.get_size();
  std::cout<<"ht size = "<<sz<<std::endl;
  std::cout<<"ht capacity = "<<cap<<std::endl;
  return 0;
}
*/
