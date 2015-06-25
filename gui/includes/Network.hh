
#ifndef NETWORK
# define NETWORK

# include <sys/types.h>
# include <sys/socket.h>
# include <netdb.h>
# include <sys/select.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <iostream>
# include <string.h>
# include <map>
# include <stdio.h>
# include <errno.h>
# include <sstream>
# include <vector>
# include <unistd.h>
# include <sstream>
# include "Graphics.hh"
# include "Exception.hh"

class Network;

typedef Event			(Network::*funcptr)(std::string command);

class				Network
{
private:
  struct protoent		*pe;
  int				socket_fd;
  int				port;
  std::string			server_ip;
  struct sockaddr_in		s_in;
  std::map<std::string, funcptr> _commandMapping;
  
private:
  Event				parseCommand(std::string);
  Event				fillMSZ(std::string command);
  Event				fillBCT(std::string command);
  Event				fillTNA(std::string command);
  Event				fillPNW(std::string command);
  Event				fillPPO(std::string command);
  Event				fillPLV(std::string command);
  Event				fillPIN(std::string command);
  Event				fillPEX(std::string command);
  Event				fillPBC(std::string command);
  Event				fillPIC(std::string command);
  Event				fillPIE(std::string command);
  Event				fillPFK(std::string command);
  Event				fillPDR(std::string command);
  Event				fillPGT(std::string command);
  Event				fillPDI(std::string command);
  Event				fillENW(std::string command);
  Event				fillEHT(std::string command);
  Event				fillEBO(std::string command);
  Event				fillEDI(std::string command);
  Event				fillSGT(std::string command);
  Event				fillSEG(std::string command);
  Event				fillSMG(std::string command);
  Event				fillSUC(std::string command);
  Event				fillSBP(std::string command);
  bool				cptWord(int nb, std::string);

public:
  Network(std::string, std::string);
  ~Network();
  bool				initNetwork();
  void				handleEvent(std::vector<Event> &);
  std::string			getMsg();
};

#endif
