#ifndef DEF
# define DEF

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
  NOSUCH,

  KEYUP,
  KEYDOWN,
  KEYLEFT,
  KEYRIGHT,
  SCROLLUP,
  SCROLLDOWN
}	     t_eventName;


typedef	 enum				e_ressource
  {
    FOOD = 0,
    LINEMATE,
    DERAUMERE,
    SIBUR,
    MENDIANE,
    PHIRAS,
    THYSTAME
  }					t_ressource;

typedef enum					e_orientation
  {
    NORTH = 1,
    EAST = 2,
    SOUTH = 3,
    WEST = 4
  }						t_orientation;

#endif
