//server.h
//interface file for all server implementations
//all derived classes need to implement
//requestHandler()
#ifndef _server_h
#define _server_h
#include "common.h"
class server
{
public:
  server(const uint16_t port, const char* ip = NULL);
  virtual ~server();
  //void run(char* rcvbuf, uint64_t rcvbuf_len);
  void run(const char* filepath);
  int accept_conn();
  virtual void requestHandler(int clfd) = 0;
  uint16_t getport();
  std::string getip();
  std::string getsvrname();
  int getsockfd();
protected:
  int socket_fd;
  struct sockaddr_in svaddr; //server address
  char buf[BUF_SIZE];
  char hostname[256];

  // disable default and copy constructor 
  // and operator=:
  server& operator=(server&){};
  server(const server&){};
  server(){};

};
#endif
