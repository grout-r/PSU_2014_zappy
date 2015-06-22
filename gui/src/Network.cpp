
#include "Network.hh"

Network::Network()
{
  this->port = 4242;
  this->server_ip = "127.0.0.1";
  this->pe = getprotobyname("TCP");
  this->s_in.sin_family = AF_INET;
  _commandMapping["msz"] = &Network::fillMSZ;
  _commandMapping["bct"] = &Network::fillBCT;
  _commandMapping["pnw"] = &Network::fillPNW;
  _commandMapping["ppo"] = &Network::fillPPO;
  _commandMapping["plv"] = &Network::fillPLV;
  _commandMapping["pin"] = &Network::fillPIN;
  _commandMapping["pex"] = &Network::fillPEX;
  _commandMapping["pbc"] = &Network::fillPBC;
  _commandMapping["pie"] = &Network::fillPIE;
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

Event				Network::parseCommand(std::string command)
{
  std::istringstream			iss(command);
  std::string				sub;
  std::map<std::string, funcptr>::iterator it;

  iss >> sub;
  it = _commandMapping.find(sub);
  if (it == _commandMapping.end())
    return Event();
  return (this->*_commandMapping[sub])(iss.str());
}

void				Network::handleEvent(std::vector<Event> &eventStack)
{
  char				buff[1024];

  fd_set rfds;
  struct timeval tv;
  int retval;
  Event				event;

  FD_ZERO(&rfds);
  FD_SET(this->socket_fd, &rfds);
  tv.tv_sec = 0;
  tv.tv_usec = 500;
  retval = select(this->socket_fd + 1, &rfds, NULL, NULL, &tv);
  if (retval == -1)
    throw (Error("select()"));
  else if (retval)
    {
      printf("Data is available now.\n");
      bzero(buff, 1024);
      read(this->socket_fd, buff, 1024);
      event = parseCommand(std::string(buff));
    }
  eventStack.push_back(event);
}

bool					Network::cptWord(int nb, std::string command)
{
  int					i;
  int					cpt;

  i = 0;
  cpt = 0;
  while (command[i])
    {
      if (command[i] == ' ')
	cpt += 1;
      i = i + 1;
    }
  if (cpt == nb)
    return (0);
  return (1);
}

Event					Network::fillMSZ(std::string command)
{
  std::istringstream			iss(command);
  std::string				sub;
  Event					event;
  
  iss >> sub;
  iss >> event.posX;
  if (event.posX <= 0)
    return event;
  iss >> event.posY;
  if (event.posY <= 0)
    return event;
  std::cout << "after return" << std::endl;
  event.eventName = MSZ;
  return event;
}

Event					Network::fillBCT(std::string command)
{
  std::istringstream			iss(command);
  std::string				sub;
  Event					event;

  if (cptWord(9, command) == 1)
    return event;
  iss >> sub;
  iss >> event.posX;
  iss >> event.posY;
  if (event.posX < 0 || event.posY < 0)
    return event;
  for (int i = 0; i != 7; i++)
    iss >> event.ressources[(t_ressource)i];
  for (int i = 0; i != 7; i++)
    {
      if (event.ressources[(t_ressource)i] < 0)
	return event;
    }
  event.eventName = BCT;
  return event;
}

Event					Network::fillPNW(std::string command)
{
  std::istringstream			iss;
  std::string				sub;
  std::string::iterator			it;
  Event					event;

  if (cptWord(6, command) == 1)
    return event;
  if ((it = std::find(command.begin(), command.end(), '#')) == command.end())
    return event;
  command.erase(it);
  iss.str(command);
  iss >> sub;
  iss >> event.playerId;
  iss >> event.posX;
  iss >> event.posY;
  iss >> event.orientation;
  iss >> event.level;
  iss >> event.teamName;
  if (event.playerId < 0 || event.posX < 0 || event.posY < 0 || event.orientation < 0 || event.level < 1 || event.teamName.size() == 0)
    return event;
  event.eventName = PNW;
  return event;
}

Event					Network::fillPPO(std::string command)
{
  std::istringstream			iss;
  std::string				sub;
  std::string::iterator			it;
  Event					event;

  if (cptWord(4, command) == 1)
    return event;
  if ((it = std::find(command.begin(), command.end(), '#')) == command.end())
    return event;
  command.erase(it);
  iss.str(command);
  iss >> sub;
  iss >> event.playerId;
  iss >> event.posX;
  iss >> event.posY;
  iss >> event.orientation;
  if (event.playerId < 0 || event.posX < 0 || event.posY < 0 || event.orientation < 0)
    return event;
  event.eventName = PPO;
  return event;
}

Event					Network::fillPLV(std::string command)
{
  std::istringstream			iss;
  std::string				sub;
  std::string::iterator			it;
  Event					event;

  if (cptWord(2, command) == 1)
    return event;
  if ((it = std::find(command.begin(), command.end(), '#')) == command.end())
    return event;
  command.erase(it);
  iss.str(command);
  iss >> sub;
  iss >> event.playerId;
  iss >> event.level;
  if (event.playerId < 0 || event.level < 1)
    return event;
  event.eventName = PLV;
  return event;
}

Event					Network::fillPIN(std::string command)
{
  std::istringstream			iss;
  std::string				sub;
  std::string::iterator			it;
  Event					event;

  if (cptWord(10, command) == 1)
    return event;
  if ((it = std::find(command.begin(), command.end(), '#')) == command.end())
    return event;
  command.erase(it);
  iss.str(command);
  iss >> sub;
  iss >> event.playerId;
  for (int i = 0; i != 7; i++)
    iss >> event.ressources[(t_ressource)i];
  for (int i = 0; i != 7; i++)
    {
      if (event.ressources[(t_ressource)i] < 0)
        return event;
    }
  event.eventName = PIN;
  return event;
}

Event					Network::fillPEX(std::string command)
{
  std::istringstream                    iss;
  std::string                           sub;
  std::string::iterator                 it;
  Event                                 event;

  if (cptWord(1, command) == 1)
    return event;
  if ((it = std::find(command.begin(), command.end(), '#')) == command.end())
    return event;
  command.erase(it);
  iss.str(command);
  iss >> sub;
  iss >> event.playerId;
  if (event.playerId < 0)
    return event;
  event.eventName = PEX;
  return event;
}

Event					Network::fillPBC(std::string command)
{
  std::istringstream                    iss;
  std::string                           sub;
  std::string::iterator                 it;
  Event                                 event;

  if (cptWord(1, command) == 1)
    return event;
  if ((it = std::find(command.begin(), command.end(), '#')) == command.end())
    return event;
  command.erase(it);
  iss.str(command);
  iss >> sub;
  iss >> event.message;
  if (event.message.size() == 0)
    return event;
  event.eventName = PBC;
  return event;
}

Event					Network::fillPIE(str::string command)
{
  std::istringstream                    iss(command);
  std::string                           sub;
  Event                                 event;

  if (cptWord(3, command) == 1)
    return event;
  iss >> sub;
  iss >> event.posX;
  iss >> event.posY;
  iss >> event.incantResult;
  if (event.posX < 0 || event.posY < 0 || event.incantResult < 0)
    return event;
  event.eventName = PIE;
  return event;
}
