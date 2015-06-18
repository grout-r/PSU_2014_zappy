//
// Event.hh for zappy in /home/roman/Documents/dev/PSU_2014_zappy/gui/src
// 
// Made by grout_r
// Login   <roman@epitech.net>
// 
// Started on  Tue Apr 28 14:54:51 2015 grout_r
// Last update Thu Jun 18 11:00:01 2015 grout_r
//

#ifndef EVENT
# define EVENT

# include <string>
# include <map>
# include "Definition.hh"

class			Event
{
public:
  std::map<t_ressource, int>	ressources;
  int			posX;
  int			posY;
  int			quantity;
  int			playerId;
  int			orientation;
  int			level;
  int			eggId;
  int			time;
  std::string		teamName;
  int			incantResult;
  std::string		message;
  int			ressourceId;

public:
  t_eventName		eventName;

public:
  Event();
  ~Event();
};

#endif
