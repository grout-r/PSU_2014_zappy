//
// Event.hh for zappy in /home/roman/Documents/dev/PSU_2014_zappy/gui/src
// 
// Made by grout_r
// Login   <roman@epitech.net>
// 
// Started on  Tue Apr 28 14:54:51 2015 grout_r
// Last update Thu Jun 18 09:26:06 2015 grout_r
//

#ifndef EVENT
# define EVENT

# include <string>

typedef enum e_eventName
{
  MSZ,
  BCT,
  TNA,
  PNW,
  PPO,
  PLV,
  PIN,
  PEX,
  PBC,
  PIC,
  PIE,
  PFK,
  PDR,
  PGT,
  PDI,
  ENW,
  EHT,
  EBO,
  EDI,
  SGT,
  SEG,
  SMG,
  SUC,
  SBP,
  NOSUCH
}	     t_eventName;

class			Event
{
public:
  int			food;
  int			minemate;
  int			deraumere;
  int			sibur;
  int			mendiane;
  int			phiras;
  int			thystame;
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
