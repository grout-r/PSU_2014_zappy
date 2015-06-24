
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
