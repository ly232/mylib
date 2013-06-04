#ifndef _linkedlist_h
#define _linkedlist_h
enum STATUS{
  FAIL = 0,
  SUCCESS = 1
};
template<typename T>
class linkedlist{
 private:
  struct node{
    T data;
    node* next;
  };
  typedef struct node node;
  node* head;
  node* tail;
 public:
   linkedlist():head(NULL),tail(NULL){};
   ~linkedlist(){
    node* next = NULL;
    node* curr = head;
    while (curr){
      next = curr->next;
      delete curr;
      curr = next;
    }
  };
   linkedlist(const linkedlist<T>& rhs){
     node* ref = rhs.head;
     if (!ref){
       node* tmp = new node;
       node* tmp2 = NULL;
       memcpy(tmp->data, ref->data, sizeof(T));
       tmp->next = NULL;
       head = tmp;
       while (ref){
	 tmp = new node;
	 
       }
     }
     else {
       head = NULL;
       tail = NULL;
     }
   };
   linkedlist<T>& operator=(const linkedlist<T>& rhs){

   };

   // client is responsible to free holder
   STATUS pop_front(T*& holder){
     if (!head) return FAIL;
     holder = new T;
     *holder = head->data;
     if (head==tail){
       delete head;
       head = NULL;
       tail = NULL;
       return SUCCESS;
     }
     node* tmp = head;
     head = head->next;
     delete tmp;
     return SUCCESS;
  }

   //client is responsible to free holder
   STATUS pop_back(T* holder){
     if (!tail) return FAIL;
     holder = new T;
     *holder = tail->data;
     if (head==tail){
       delete tail;
       head = NULL;
       tail = NULL;
       return SUCCESS;
     }
     node* tmp1 = head;
     node* tmp2 = head->next;
     while (tmp2!=tail){
       tmp1 = tmp2;
       tmp2 = tmp2->next;
     }
     delete tmp2;
     tmp1->next = NULL;
     tail = tmp1;
     return SUCCESS;
     
  }
  STATUS prepend(T* data){
    if (!data) return FAIL;
    node* newnode = new node;
    newnode->data = *data;
    newnode->next = head;
    if (head==NULL&&tail==NULL){
      head = newnode;
      tail = newnode;
      return SUCCESS;
    }
    node* tmp = head;
    head = newnode;
    head->next = tmp;
    return SUCCESS;
  };
  STATUS append(T* data){
    if (!data) return FAIL;
    node* newnode = new node;
    newnode->data = *data;
    newnode->next = NULL;
    if (head==NULL&&tail==NULL){
      tail = newnode;
      head = newnode;
      return SUCCESS;
    }
    node* tmp = tail;
    tail = newnode;
    tmp->next = tail;
    return SUCCESS;
  };
};
#endif
