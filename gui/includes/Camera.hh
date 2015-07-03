
#ifndef CAMERA
# define CAMERA

# include <vector>
# include <map>
# include <sstream>
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
  std::string			_ip;
  std::string			_port;
  
private:
  std::vector<Event>		_eventStack;
  std::map<t_eventName, execFuncPtr> _bindExecFuncPtr;

public:
  Camera(int ac, char **av);
  ~Camera();

private:
  void				updateGame();
  void				treatEvent();

public:
  void			        setParams(int ac, char **av);
  void				loop();
  
private:
  void				execMSZ(Event);
  void				execBCT(Event);
  void				execPNW(Event);  
  void				execPPO(Event);  
  void				execPLV(Event);
  void				execPIN(Event);
  void				execPBC(Event);
  void				execENW(Event);
  void				execSEG(Event);
  void				execEBO(Event);
  void				execPDI(Event);
  void				execEHT(Event);
  void				execNOTHING(Event);
  void				execCHFOCUS(Event);
 
private:
  void				execKEYMOVE(Event);

};

#endif
