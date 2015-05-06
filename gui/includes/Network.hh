//
// Network.hh for zappy in /home/roman/Documents/dev/PSU_2014_zappy/gui/src
// 
// Made by grout_r
// Login   <roman@epitech.net>
// 
// Started on  Tue Apr 28 15:36:18 2015 grout_r
// Last update Wed May  6 09:51:31 2015 grout_r
//

#ifndef NETWORK
# define NETWORK

# include <sys/types.h>
# include <sys/socket.h>
# include <netdb.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <iostream>
# include <string.h>
# include "Graphics.hh"

class				Network
{
private:
  struct protoent		*pe;
  int				socket_fd;
  int				port;
  std::string			server_ip;
  struct sockaddr_in		s_in;
public:
  Network();
  ~Network();
  bool				initNetwork();
  void				handleEvent(Graphics *graph);
};

#endif
