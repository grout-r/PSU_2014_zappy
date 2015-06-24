
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
