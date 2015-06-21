//
// Camera.cpp for zappy in /home/roman/Documents/dev/PSU_2014_zappy/gui/src
// 
// Made by grout_r
// Login   <roman@epitech.net>
// 
// Started on  Tue Apr 28 15:30:33 2015 grout_r
// Last update Mon Jun 22 14:30:06 2015 grout_r
//

#include "Camera.hh"

Camera::Camera()
{
  _graph = new Graphics();
  _net = new Network();
  _map = new Map(std::make_pair(100, 100));
  _bindExecFuncPtr[MSZ] = &Camera::execMSZ;
  _bindExecFuncPtr[BCT] = &Camera::execBCT;
  _bindExecFuncPtr[PNW] = &Camera::execPNW;
  _bindExecFuncPtr[PPO] = &Camera::execPPO;
  _bindExecFuncPtr[PLV] = &Camera::execPLV;
}

Camera::~Camera()
{
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
  _map->addPlayer(1, std::make_pair(5, 5), SOUTH, 0, "Les patates en folies");
  if (_net->initNetwork() == false)
    exit(-1);
  while (true)
    {
      _graph->refreshScreen(_map);
      _graph->handleEvent();
      _net->handleEvent(_eventStack);
      treatEvent();
    }
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
