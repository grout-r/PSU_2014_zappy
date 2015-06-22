
#include "Camera.hh"

Camera::Camera(int ac, char **av)
{
  setParams(ac, av);
  _net = new Network(_ip, _port);
  _map = new Map(std::make_pair(10, 10));
  _graph = new Graphics(_map->getSize());
  _bindExecFuncPtr[MSZ] = &Camera::execMSZ;
  _bindExecFuncPtr[BCT] = &Camera::execBCT;
  _bindExecFuncPtr[PNW] = &Camera::execPNW;
  _bindExecFuncPtr[PPO] = &Camera::execPPO;
  _bindExecFuncPtr[PLV] = &Camera::execPLV;
  _bindExecFuncPtr[ENW] = &Camera::execENW;
  _bindExecFuncPtr[PIN] = &Camera::execPIN;
  _bindExecFuncPtr[PEX] = &Camera::execNOTHING;
  _bindExecFuncPtr[PBC] = &Camera::execPBC;
  _bindExecFuncPtr[PIC] = &Camera::execNOTHING;
  _bindExecFuncPtr[PIE] = &Camera::execNOTHING;
  _bindExecFuncPtr[PFK] = &Camera::execNOTHING;
  _bindExecFuncPtr[PDR] = &Camera::execNOTHING;
  _bindExecFuncPtr[PGT] = &Camera::execNOTHING;
  _bindExecFuncPtr[PDI] = &Camera::execPDI;
  _bindExecFuncPtr[EHT] = &Camera::execEHT;
  _bindExecFuncPtr[EBO] = &Camera::execEBO;
  _bindExecFuncPtr[EDI] = &Camera::execNOTHING;
  _bindExecFuncPtr[SGT] = &Camera::execNOTHING;
  _bindExecFuncPtr[SEG] = &Camera::execSEG;
  _bindExecFuncPtr[SMG] = &Camera::execNOTHING;

  _bindExecFuncPtr[KEYLEFT] = &Camera::execKEYMOVE;  
  _bindExecFuncPtr[KEYRIGHT] = &Camera::execKEYMOVE;  
  _bindExecFuncPtr[KEYUP] = &Camera::execKEYMOVE;  
  _bindExecFuncPtr[KEYDOWN] = &Camera::execKEYMOVE;
  _bindExecFuncPtr[SCROLLUP] = &Camera::execKEYMOVE;
  _bindExecFuncPtr[SCROLLDOWN] = &Camera::execKEYMOVE;
  _bindExecFuncPtr[CHFOCUS] = &Camera::execCHFOCUS;
}

Camera::~Camera()
{
}

void				Camera::setParams(int ac, char **av)
{
  if (ac != 3)
    {
      std::cout << " Usage : ./zappy_gui [IP] [PORT]" << std::endl;
      exit(-1);
    }
  _ip = std::string(av[1]);
  _port = std::string(av[2]);
}

void				Camera::treatEvent()
{
  for (size_t i = 0; i != _eventStack.size(); i++)
    {
      if (_eventStack[i].eventName != NOSUCH)
	{
	  (this->*_bindExecFuncPtr[_eventStack[i].eventName])(_eventStack[i]);
	} 
    }
  _eventStack.clear();
}

void				Camera::loop()
{
  if (_net->initNetwork() == false)
    exit(-1);
  while (true)
    {
      _graph->refreshScreen(_map);
      _graph->handleEvent(_eventStack);
      _net->handleEvent(_eventStack);
      treatEvent();
      updateGame();
    }
}

void				Camera::updateGame()
{
  _map->updatePlayers();
}

void				Camera::execNOTHING(Event)
{
  return ;
}

void				Camera::execMSZ(Event event)
{
  _map->resizeMap(std::make_pair(event.posX, event.posY));
}

void				Camera::execBCT(Event event)
{
  _map->updateCase(std::make_pair(event.posX, event.posY), event.ressources);
}

void				Camera::execPNW(Event event)
{
  _map->addPlayer(event.playerId, std::make_pair(event.posX, event.posY), 
		  (t_orientation)event.orientation, event.level, event.teamName);
}

void				Camera::execPPO(Event event)
{
  _map->movePlayer(event.playerId, std::make_pair(event.posX, event.posY),
		   (t_orientation)event.orientation);
}

void				Camera::execPLV(Event event)
{
  _map->pexPlayer(event.playerId, event.level);
}

void				Camera::execPIN(Event event)
{
  _map->updateInventory(event.playerId, event.ressources);
}

void				Camera::execPBC(Event event)
{
  _map->startBroadcast(event.playerId, event.message);
}

void				Camera::execEBO(Event event)
{
  _map->deleteEgg(event.eggId);
}

void				Camera::execEHT(Event event)
{
  _map->deleteEgg(event.eggId);
}

void				Camera::execPDI(Event event)
{
  _map->deletePlayer(event.playerId);
}

void				Camera::execENW(Event event)
{
  _map->addEgg(event.eggId, event.playerId, std::make_pair(event.posX, event.posY));
}

void				Camera::execSEG(Event event)
{
  _map->gameOver(event.teamName);
}

void				Camera::execKEYMOVE(Event event)
{
  _graph->moveView(event.eventName);
}

void				Camera::execCHFOCUS(Event event)
{
  std::pair<int, int>		size = _map->getSize();
  std::pair<int, int>		newFocus;

  if (event.posX < 0 || event.posX > size.first || 
      event.posY < 0 || event.posY > size.second)
    {
      newFocus = std::make_pair(-1 , -1);
    }
  else
    newFocus = std::make_pair(event.posX, event.posY);
  _map->setHud(newFocus);
}
