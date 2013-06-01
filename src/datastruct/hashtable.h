#ifndef _hash_table_h
#define _hash_table_h
#include <string>
#include <list>
enum STATUS{
 FAIL=0,
 SUCCESS=1
};
typedef struct HashObj HashObj;
template <typename T>
class HashTable
{
 public:
 HashTable():capacity(1024),size(0),data(NULL)
  {
    data = new std::list<HashObj>[capacity];
  };
  ~HashTable()
  {
    delete [] data;
  };

  /***************************************/
  /* STATUS HashTable<T>::put(std::string key, const T& value)
  /* put item with key
  /* fails if key already exists 
  /***************************************/
  STATUS put(std::string key, const T& value)
  {
    std::size_t idx = hashfunc(key);
    //make sure key does not exist in hash table:
    typename std::list<HashObj>::const_iterator cit = data[idx].begin();
    for (;cit!=data[idx].end();cit++){
      if (cit->key==key)
	return FAIL; //duplicate key not allowed in hash table
    }
    if (size>capacity/2)
      rehash();
    HashObj ho = HashObj();
    ho.key = key;
    ho.value = value;
    data[idx].push_back(ho);
    size++;
    return SUCCESS;
  };

  /***************************************/
  /* STATUS delete(std::string key)
  /* remove the item with key key
  /***************************************/
  
  STATUS remove(std::string key, T* const holder){
    std::size_t idx = hashfunc(key);
    typename std::list<HashObj>::iterator it = data[idx].begin();
    for (;it!=data[idx].end();it++){
      if (it->key==key){
	if (holder)
	  *holder = it->value;
	data[idx].erase(it);	
	return SUCCESS;
      }
    }
    return FAIL;
  };
  
  /***************************************/
  /* STATUS HashTable<T>::get(const std::string& key, T* const holder) const
  /* get the item associated with key
  /* if holder is NULL, will not return the item
  /* returns SUCCESS if found; FAIL otherwise
  /***************************************/
  STATUS get(const std::string& key, T* const holder) const
  {
    std::size_t idx = hashfunc(key);
    if (data[idx].size()==0)
      return FAIL; //not found: no hashed index
    typename std::list<HashObj>::const_iterator cit = data[idx].begin();
    for (;cit!=data[idx].end();cit++){
      if (cit->key==key){
	if (holder)
	  *holder = cit->value;
	return SUCCESS;
      }
    }
    return FAIL; //not found: wrong key
  };
  std::size_t get_capacity() const {return capacity;};
 private:
  struct HashObj{
    std::string key;
    T value;
  };
  STATUS rehash()
  {
    return FAIL;
  };
  std::size_t hashfunc(const std::string& key) const
  {
    std::size_t len = key.size();
    std::size_t hashval = 0;
    for (std::size_t i=0; i<len; i++){
      hashval += (int)key[i];
    };
    hashval %= capacity;
    return hashval;
  };
  std::size_t capacity;
  std::size_t size;
  std::list<HashObj>* data;
};
#endif