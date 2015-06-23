//
// Camera.hh for zappy in /home/roman/Documents/dev/PSU_2014_zappy/gui/src
// 
// Made by grout_r
// Login   <roman@epitech.net>
// 
// Started on  Tue Apr 28 15:30:30 2015 grout_r
// Last update Tue Jun 23 14:22:41 2015 grout_r
//

#ifndef CAMERA
# define CAMERA

# include <vector>
# include <map>
# include "Graphics.hh"
# include "Network.hh"

class				Camera;

typedef void			(Camera::*execFuncPtr)(Event);

class				Camera
{
private:
  Graphics			*_graph;
  Network			*_net;
  Map				*_map;  
  
private:
  std::vector<Event>		_eventStack;
  std::map<t_eventName, execFuncPtr> _bindExecFuncPtr;

private:
  void				treatEvent();

public:
  Camera();
  ~Camera();
  void				loop();
  
private:
  void				execMSZ(Event);
  void				execBCT(Event);
  void				execPNW(Event);  
  void				execPPO(Event);  
  void				execPLV(Event);
  void				execPIN(Event);
  void				execENW(Event);
private:
  void				execKEYMOVE(Event);

};

#endif
