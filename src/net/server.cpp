//server.cpp
#include "server.h"
server::server(const uint16_t port, const char* ip)
{
  try
  {
    //socket construction:
    if ((socket_fd=socket(AF_INET, SOCK_STREAM, 0))==-1)
      throw SOCKET_CONSTRUCT_ERROR;

    /* setsockopt: Handy debugging trick that lets 
       * us rerun the server immediately after we kill it; 
     * otherwise we have to wait about 20 secs. 
     * Eliminates "ERROR on binding: Address already in use" error. 
     */
    int optval = 1;
    setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR, 
	     (const void *)&optval , sizeof(int));

    memset(hostname, 0, 256);
    gethostname(hostname, 256);
    memset(&svaddr, 0, sizeof(struct sockaddr_in));
    svaddr.sin_family = AF_INET;
    svaddr.sin_port = htons(port);
    if (!ip)
    {
      // code from 
      // http://stackoverflow.com/questions/212528/get-the-ip-address-of-the-machine
      bool foundip = false;
      struct ifaddrs* ifaAddrStruct = NULL;
      struct ifaddrs* ifa = NULL; //iterator to scan each ip address on host
      getifaddrs(&ifaAddrStruct);
      for(ifa = ifaAddrStruct; ifa!=NULL; ifa = ifa->ifa_next)
      {
	if (ifa->ifa_addr->sa_family==AF_INET //ipv4
	    && strcmp(ifa->ifa_name,"eth0")==0) //ethernet
	{
	  //only deal with ethernet ipv4 for now...may support ipv6 in future
	  svaddr.sin_addr = ((struct sockaddr_in*)ifa->ifa_addr)->sin_addr;
	  foundip = true;
	  break;
	}
      }
      if (!foundip)
	throw SOCKET_BIND_ERROR;
    }
    else
      inet_pton(AF_INET, ip, (void*)&svaddr.sin_addr);
        //convert presentation format ip address to struct in_addr binary format

    //socket binding:
    if (bind(socket_fd, (struct sockaddr*)&svaddr, sizeof(struct sockaddr_in))==-1)
      throw SOCKET_BIND_ERROR;

    //socket listening:
    if (listen(socket_fd, MAX_CONN)==-1)
      throw SOCKET_LISTEN_ERROR;
  }
  catch(int e)
  {
    throw;
  }
}

server::~server()
{
  if (close(socket_fd)==-1)
    throw SOCKET_CLOSE_ERROR;
}

// returns client socket file descriptor
// will also print client address info in stdout
int server::accept_conn()
{
  try
  {    
    struct sockaddr_in claddr; //client address
    socklen_t claddr_len = sizeof(claddr);
    struct hostent *hostp; // client host info
    char *hostaddrp; // dotted decimal host addr string
    int comm_sock_fd; // socket descriptor to communicat with clienet
                      // note this is not the same as sock_fd!!!

    //socket accepting:
    if ((comm_sock_fd = accept(socket_fd, (struct sockaddr*) &claddr, &claddr_len))==-1)
      throw SOCKET_ACCEPT_ERROR;
    // gethostbyaddr: determine who sent the message 
    hostp = gethostbyaddr((const char *)&claddr.sin_addr.s_addr, 
			  sizeof(claddr.sin_addr.s_addr), AF_INET);
    if (hostp == NULL)
      throw SOCKET_ACCEPT_ERROR;
    hostaddrp = inet_ntoa(claddr.sin_addr);
    if (hostaddrp == NULL)
      throw SOCKET_ACCEPT_ERROR;
    printf("server established connection with %s (%s)\n", 
	   hostp->h_name, hostaddrp);
    return comm_sock_fd;
  }
  catch(int e)
  {
    throw;
  }
}


void server::run(const char* filepath)
{
  ssize_t byte_received = 0;
  int fd;
  try
  {    
    struct sockaddr_in claddr; //client address
    socklen_t claddr_len = sizeof(claddr);
    struct hostent *hostp; // client host info
    char *hostaddrp; // dotted decimal host addr string
    int comm_sock_fd; // socket descriptor to communicat with clienet
                      // note this is not the same as sock_fd!!!

    //socket accepting:
    if ((comm_sock_fd = accept(socket_fd, (struct sockaddr*) &claddr, &claddr_len))==-1)
      throw SOCKET_ACCEPT_ERROR;
    fd = open(filepath,O_RDWR | O_APPEND | O_CREAT);
    if (fd==-1)
      throw FILE_IO_ERROR;
    // gethostbyaddr: determine who sent the message 
    hostp = gethostbyaddr((const char *)&claddr.sin_addr.s_addr, 
			  sizeof(claddr.sin_addr.s_addr), AF_INET);
    if (hostp == NULL)
      throw SOCKET_ACCEPT_ERROR;
    hostaddrp = inet_ntoa(claddr.sin_addr);
    if (hostaddrp == NULL)
      throw SOCKET_ACCEPT_ERROR;
    printf("server established connection with %s (%s)\n", 
	   hostp->h_name, hostaddrp);

    memset(buf, 0, BUF_SIZE);
    while ((byte_received=read(comm_sock_fd, buf, BUF_SIZE))>0)
    {
      if (write(fd, buf, byte_received)!=byte_received)
	throw FILE_IO_ERROR;
    }
    if (close(comm_sock_fd)==-1)
      throw SOCKET_CLOSE_ERROR
    if (close(fd)==-1)
      throw FILE_IO_ERROR;
    if (byte_received==-1)
      throw SOCKET_RECEIVE_ERROR;
    //send ack to client:
    if (write(socket_fd, "ACK", 4)!=4)
      throw SOCKET_ACK_ERROR;
  }
  catch(int e)
  {
    throw;
  }
}

uint16_t server::getport()
{
  return ntohs(svaddr.sin_port);
}

std::string server::getip()
{
  char ip[INET_ADDRSTRLEN];
  inet_ntop(AF_INET, (void*)&svaddr.sin_addr, ip, INET_ADDRSTRLEN);
  return std::string(ip);
}

std::string server::getsvrname()
{
  return std::string(hostname);
}

int server::getsockfd()
{
  return socket_fd;
}
