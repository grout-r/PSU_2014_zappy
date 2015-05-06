//
// Network.cpp for zappy in /home/roman/Documents/dev/PSU_2014_zappy/gui/src
// 
// Made by grout_r
// Login   <roman@epitech.net>
// 
// Started on  Tue Apr 28 15:36:25 2015 grout_r
// Last update Wed May  6 11:07:12 2015 grout_r
//

#include "Network.hh"

Network::Network()
{
  this->port = 4242;
  this->server_ip = "127.0.0.1";


  this->pe = getprotobyname("TCP");
  this->s_in.sin_family = AF_INET;
}

Network::~Network()
{
}

bool				Network::initNetwork()
{
  try
    {
      this->s_in.sin_port = htons(this->port);
      this->s_in.sin_addr.s_addr = inet_addr(this->server_ip.c_str());
      if ((this->socket_fd = socket(AF_INET, SOCK_STREAM, this->pe->p_proto)) == -1)
	throw (Error("Error on socket : " + std::string(strerror(errno))));
      if (connect(this->socket_fd, (struct sockaddr *)&(this->s_in),
		  sizeof(this->s_in)) == -1)
	throw (Error("Error on connect : " + std::string(strerror(errno))));
      return (true);
    }
  catch (Error e)
    {
      std::cerr << e.what() << std::endl;
    }
  return (false);
}

void				Network::handleEvent(Graphics *graph)
{
  (void)graph;

  char				buff[1024];

  fd_set rfds;
  struct timeval tv;
  int retval;

  FD_ZERO(&rfds);
  FD_SET(this->socket_fd, &rfds);
  tv.tv_sec = 0;
  tv.tv_usec = 500;
  retval = select(this->socket_fd + 1, &rfds, NULL, NULL, &tv);
  if (retval == -1)
    throw (Error( strerror("select()"));
  else if (retval)
    {
      printf("Data is available now.\n");
      bzero(buff, 1024);
      read(this->socket_fd, buff, 1024);
      std::cout << buff << std::endl;
    }
}
