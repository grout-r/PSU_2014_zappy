
#include "Network.hh"

Network::Network(std::string ip, std::string port)
{
  std::stringstream ss(port);

  ss >> this->port;
  this->server_ip = ip;
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
  _commandMapping["pfk"] = &Network::fillPFK;
  _commandMapping["pdr"] = &Network::fillPDR;
  _commandMapping["pgt"] = &Network::fillPGT;
  _commandMapping["pdi"] = &Network::fillPDI;
  _commandMapping["enw"] = &Network::fillENW;
  _commandMapping["eht"] = &Network::fillEHT;
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
      if (write(socket_fd, "GRAPHIC\n", strlen("GRAPHIC\n")) < 0)
	return (false);
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
    {
      return Event();
    }
  return (this->*_commandMapping[sub])(iss.str());
}

void				Network::handleEvent(std::vector<Event> &eventStack)
{
  fd_set rfds;
  struct timeval tv;
  int retval;
  Event				event;
  std::string		        buffer;

  FD_ZERO(&rfds);
  FD_SET(this->socket_fd, &rfds);
  tv.tv_sec = 0;
  tv.tv_usec = 500;
  retval = select(this->socket_fd + 1, &rfds, NULL, NULL, &tv);
  if (retval == -1)
    throw (Error("select()"));
  else if (retval)
    {
      buffer = getMsg();
      std::cout << buffer << std::endl;
      event = parseCommand(buffer);
    }
  eventStack.push_back(event);
}

std::string				Network::getMsg()
{
  char					tmp;
  std::string				ret;
  
  while (tmp != '\n')
    {
      read(this->socket_fd, &tmp, 1);
      ret.push_back(tmp);
    }
  return (ret);
}

int					Network::cptWord(int nb, std::string command)
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
  
  std::cout << "MSZ" << std::endl;
  if (cptWord(2, command) == 1)
    return event;
  iss >> sub;
  iss >> event.posX;
  if (event.posX <= 0)
    return event;
  iss >> event.posY;
  if (event.posY <= 0)
    return event;
  event.eventName = MSZ;
  return event;
}

Event					Network::fillBCT(std::string command)
{
  std::istringstream			iss(command);
  std::string				sub;
  Event					event;

  std::cout << "BCT" << std::endl;
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
  std::istringstream			iss(command);
  std::string				sub;
  Event					event;

  std::cout << "PNW" << std::endl;
  if (cptWord(6, command) == 1)
    return event;
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
  std::istringstream			iss(command);
  std::string				sub;
  Event					event;

  std::cout << "PPO" << std::endl;
  if (cptWord(4, command) == 1)
    return event;
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
  std::istringstream			iss(command);
  std::string				sub;
  Event					event;

  std::cout << "PLV" << std::endl;
  if (cptWord(2, command) == 1)
    return event;
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
  std::istringstream			iss(command);
  std::string				sub;
  Event					event;

  std::cout << "PIN" << std::endl;
  if (cptWord(10, command) == 1)
    return event;
  iss >> sub;
  iss >> event.playerId;
  iss >> event.posX;
  iss >> event.posY;
  for (int i = 0; i != 7; i++)
    iss >> event.ressources[(t_ressource)i];
  for (int i = 0; i != 7; i++)
    {
      if (event.ressources[(t_ressource)i] < 0)
        return event;
    }
  event.eventName = PIN;
  std::cout << "PIN2" << std::endl;
  return event;
}

Event					Network::fillPEX(std::string command)
{
  std::istringstream                    iss(command);
  std::string                           sub;
  Event                                 event;

  std::cout << "PEX" << std::endl;
  if (cptWord(1, command) == 1)
    return event;
  iss >> sub;
  iss >> event.playerId;
  if (event.playerId < 0)
    return event;
  event.eventName = PEX;
  return event;
}

Event					Network::fillPBC(std::string command)
{
  std::istringstream                    iss(command);
  std::string                           sub;
  Event                                 event;

  std::cout << "PBC" << std::endl;
  if (cptWord(2, command) == 1)
    return event;
  iss >> sub;
  iss >> event.message;
  if (event.message.size() == 0)
    return event;
  event.eventName = PBC;
  return event;
}

Event					Network::fillPIE(std::string command)
{
  std::istringstream                    iss(command);
  std::string                           sub;
  Event                                 event;

  std::cout << "PIE" << std::endl;
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

Event					Network::fillPFK(std::string command)
{
  std::istringstream			iss(command);
  std::string				sub;
  Event					event;

  std::cout << "PFK" << std::endl;
  if (cptWord(1, command) == 1)
    return event;
  iss >> sub;
  iss >> event.playerId;
  if (event.playerId < 0)
    return event;
  event.eventName = PFK;
  return event;
}

Event					Network::fillPDR(std::string command)
{
  std::istringstream			iss(command);
  std::string				sub;
  Event					event;

  std::cout << "PDR" << std::endl;
  if (cptWord(2, command) == 1)
    return event;
  iss >> sub;
  iss >> event.playerId;
  iss >> event.ressourceId;
  if (event.playerId < 0 || event.ressourceId < 0)
    return event;
  event.eventName = PDR;
  return event;
}

Event					Network::fillPGT(std::string command)
{
  std::istringstream			iss(command);
  std::string				sub;
  Event					event;

  std::cout << "PGT" << std::endl;
  if (cptWord(2, command) == 1)
    return event;
  iss >> sub;
  iss >> event.playerId;
  iss >> event.ressourceId;
  if (event.playerId < 0 || event.ressourceId < 0)
    return event;
  event.eventName = PGT;
  return event;
}

Event					Network::fillPDI(std::string command)
{
  std::istringstream			iss(command);
  std::string				sub;
  Event					event;

  std::cout << "PDI" << std::endl;
  if (cptWord(1, command) == 1)
    return event;
  iss >> sub;
  iss >> event.playerId;
  if (event.playerId < 0)
    return event;
  event.eventName = PDI;
  return event;
}

Event					Network::fillENW(std::string command)
{
  std::istringstream			iss(command);
  std::string				sub;
  Event					event;

  std::cout << "ENW" << std::endl;
  if (cptWord(4, command) == 1)
    return event;
  iss >> sub;
  iss >> event.eggId;
  iss >> event.playerId;
  iss >> event.posX;
  iss >> event.posY;
  if (event.eggId < 0 || event.playerId < 0 || event.posX < 0 || event.posY < 0)
    return event;
  event.eventName = ENW;
  return event;
}

Event					Network::fillEHT(std::string command)
{
  std::istringstream			iss(command);
  std::string				sub;
  Event					event;

  std::cout << "EHT" << std::endl;
  if (cptWord(1, command) == 1)
    return event;
  iss >> sub;
  iss >> event.eggId;
  if (event.eggId < 0)
    return event;
  event.eventName = EHT;
  return event;
}
