//
// Network.cpp for zappy in /home/roman/Documents/dev/PSU_2014_zappy/gui/src
// 
// Made by grout_r
// Login   <roman@epitech.net>
// 
// Started on  Tue Apr 28 15:36:25 2015 grout_r
// Last update Wed May  6 10:02:45 2015 grout_r
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
  this->s_in.sin_port = htons(this->port);
  this->s_in.sin_addr.s_addr = inet_addr(this->server_ip.c_str());
  this->socket_fd = socket(AF_INET, SOCK_STREAM, this->pe->p_proto);
  if (this->socket_fd == -1)
    std::cout << "c'est la merde" << std::endl;
  std::cout << "ah que coucou " << this->socket_fd  << std::endl;
  if (connect(this->socket_fd, (struct sockaddr *)&(this->s_in),
              sizeof(this->s_in)) == -1)
    std::cerr << "bug" << std::endl;
  if (write(this->socket_fd, "salut", strlen("salut")) == 0)
    std::cerr << "bite lol" << std::endl;
  return true;
}

void				Network::handleEvent(Graphics *graph)
{
  (void)graph;
}
